//
// Created by nolasco on 10/06/20.
//

#include "PlayerBrain.h"

#include <controller/input/Input.h>
#include <libs/constants/gameconstants.h>

#include "view/Printer.h"
#include "view/input-prompt/Input-Prompter.h"

namespace controller::brain {

Player::Player() : activeSubmenu(Action::UNDEFINED) {
  makeBranch(Action::UNDEFINED, {Action::SKIP_TURN, Action::MENU, Action::ATTACK, Action::INVENTORY, Action::TEAM,
                                 Action::SHOP, Action::QUEST, Action::TRAVEL, Action::SPECIAL});

  makeBranch(Action::MENU, {Action::MENU_SAVE, Action::MENU_TUTORIAL, Action::MENU_TERMINATE});
  makeBranch(Action::ATTACK, {Action::ATTACK_CHARACTER, Action::ATTACK_BUILDING, Action::ATTACK_STRUCTURE});
  makeBranch(Action::INVENTORY, {Action::INVENTORY_PICKUP, Action::INVENTORY, Action::INVENTORY_DROP, Action::INVENTORY,
                                 Action::INVENTORY_USE});
  makeBranch(Action::TEAM,
             {Action::TEAM_CREATE, Action::TEAM_DISBAND, Action::TEAM_TRADE, Action::TEAM_KICK, Action::TEAM_INVITE});
  makeBranch(Action::SHOP, {Action::SHOP_BUY, Action::SHOP_SELL});
  makeBranch(Action::QUEST, {Action::QUEST_ABANDON, Action::QUEST_FINISH});
  makeBranch(Action::SPECIAL, {Action::SPECIAL_SUMMON, Action::SPECIAL_PICKPOCKET, Action::SPECIAL_POSSESS,
                               Action::SPECIAL_READ, Action::SPECIAL_CALL});
  makeBranch(Action::TRAVEL, {Action::TRAVEL_EXTERIOR, Action::TRAVEL_INTERIOR});

  makeBranch(Action::SPECIAL_CALL, {Action::SPECIAL_CALL_REINFORCEMENT, Action::SPECIAL_CALL_ENEMY});
}

Decision Player::think(const Snapshot &snapshot) {
  activeSubmenu = Action::UNDEFINED;
  snap = snapshot;

  // TODO: Change to have time termination
  // TODO: Change to disable invalid options
  while (true) {
    view::printer::printScreen(snapshot);

    if (!gameconstants::submenuInfo(activeSubmenu).terminal) {
      selectSubmenu();
    } else {
      Decision decision{};
      switch (activeSubmenu) {
        case Action::ATTACK_CHARACTER:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.characters).parsed};
          break;
        case Action::ATTACK_BUILDING:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.buildings).parsed};
          break;
        case Action::ATTACK_STRUCTURE:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.structures).parsed};
          break;
        case Action::INVENTORY_PICKUP:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.floor).parsed};
          break;
        case Action::INVENTORY_DROP:
          decision = drop_item();
          break;
        case Action::INVENTORY_USE:
          decision = use_item();
          break;
        case Action::TRAVEL_INTERIOR:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.buildings).parsed};
          break;
        case Action::TRAVEL_EXTERIOR:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.exteriors).parsed};
          break;
        case Action::SPECIAL_SUMMON:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_PICKPOCKET: {
          const auto who = selectFromVector(snap.characters).parsed;
          const auto itemInput = selectFromVector(snap.ownedBy.find(who)->second);
          decision = Decision{activeSubmenu, snap.character.id, itemInput.parsed};
          break;
        }
        case Action::SPECIAL_POSSESS:
          decision = Decision{activeSubmenu, snap.character.id, selectFromVector(snap.buildings).parsed};
          break;
        case Action::SKIP_TURN:
          [[fallthrough]];
        default:
          decision = Decision{Action::SKIP_TURN};
          break;
      }

      if (gameconstants::submenuInfo(activeSubmenu).terminal) {
        return decision;
      }
    }
  }
}

Decision Player::use_item() {
  const auto cLen = snap.consumables.size();
  const auto eLen = snap.equippables.size();
  if (cLen == 0 && eLen == 0) {
    view::input::invalid(gameconstants::submenuInfo(activeSubmenu).prompt);
    activeSubmenu = Action::UNDEFINED;
    return Decision{Action::UNDEFINED};
  }

  view::input::items(gameconstants::submenuInfo(activeSubmenu).prompt, snap);
  ResourceId parsedInput{0};
  const auto in = controller::input::numeric(eLen + cLen);
  if (in <= cLen) {
    parsedInput = snap.consumables[in - 1].id;
  } else {
    parsedInput = snap.equippables[in - cLen - 1].id;
  }
  return Decision{activeSubmenu, snap.character.id, parsedInput};
}

Decision Player::drop_item() {
  const auto cLen = snap.consumables.size();
  const auto eLen = snap.equippables.size();
  if (cLen == 0 && eLen == 0) {
    view::input::invalid(gameconstants::submenuInfo(activeSubmenu).prompt);
    activeSubmenu = Action::UNDEFINED;
    return Decision{Action::UNDEFINED};
  }

  view::input::items(gameconstants::submenuInfo(activeSubmenu).prompt, snap);
  ResourceId parsedInput{0};
  Quantity quantity{0};
  const auto in = controller::input::numeric(eLen + cLen);
  if (in <= cLen) {
    parsedInput = snap.consumables[in - 1].id;
    quantity = selectItemQuantity(snap.consumables, {static_cast<Quantity>(in - 1), parsedInput});
  } else {
    parsedInput = snap.equippables[in - cLen - 1].id;
    quantity = selectItemQuantity(snap.equippables, {static_cast<Quantity>(in - cLen - 1), parsedInput});
  }
  return Decision{activeSubmenu, parsedInput, snap.location.id, quantity};
}

void Player::selectSubmenu() {
  std::vector<MenuState> options;
  std::string validInput;
  for (const auto &[endSubmenu, startSubmenu] : decisionTree) {
    if (startSubmenu == activeSubmenu && menuHandler.shouldDisplaySubmenu(snap, endSubmenu)) {
      const auto &submenuInfo = gameconstants::submenuInfo(endSubmenu);
      options.emplace_back(submenuInfo);
      validInput += submenuInfo.transition;
    }
  };

  view::input::playerMenu(options);
  const auto in = controller::input::alphanum(validInput);
  activeSubmenu = options[validInput.find(in)].action;
}

void Player::makeBranch(Action startSubmenu, const std::initializer_list<Action> &endSubmenus) {
  for (auto endSubmenu : endSubmenus) {
    decisionTree.emplace(endSubmenu, startSubmenu);
  }
}

template <typename T> ConsoleIn Player::selectFromVector(const std::vector<T> &vector) {
  if (vector.empty()) {
    view::input::invalid(gameconstants::submenuInfo(activeSubmenu).prompt);
    activeSubmenu = Action::UNDEFINED;
    return {0, 0};
  }

  view::input::generic(gameconstants::submenuInfo(activeSubmenu).prompt, vector);
  const auto in = controller::input::numeric(vector.size()) - 1;
  const auto parsedInput = vector[in].id;
  return ConsoleIn{static_cast<Quantity>(in), parsedInput};
}

template <typename T> Quantity Player::selectItemQuantity(const std::vector<T> &vector, ConsoleIn input) {
  if (vector.empty()) {
    view::input::invalid("No items available!");
    activeSubmenu = Action::UNDEFINED;
    return 0;
  }

  const auto max = vector[input.raw].entity->quantity;
  if (max == 1) {
    return 1;
  }
  view::input::quantity(max);
  return controller::input::numeric(max);
}

} // namespace controller::brain
