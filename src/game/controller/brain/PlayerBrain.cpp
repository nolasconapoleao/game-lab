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
  makeMenuConnection(Action::UNDEFINED, {Action::SKIP_TURN, Action::MENU, Action::ATTACK, Action::INVENTORY,
                                         Action::TEAM, Action::SHOP, Action::QUEST, Action::TRAVEL, Action::SPECIAL});

  makeMenuConnection(Action::MENU, {Action::MENU_SAVE, Action::MENU_TUTORIAL, Action::MENU_TERMINATE});
  makeMenuConnection(Action::ATTACK, {Action::ATTACK_CHARACTER, Action::ATTACK_BUILDING, Action::ATTACK_STRUCTURE});
  makeMenuConnection(Action::INVENTORY, {Action::INVENTORY_PICKUP, Action::INVENTORY, Action::INVENTORY_DROP,
                                         Action::INVENTORY, Action::INVENTORY_USE});
  makeMenuConnection(Action::TEAM, {Action::TEAM_CREATE, Action::TEAM_DISBAND, Action::TEAM_TRADE, Action::TEAM_KICK,
                                    Action::TEAM_INVITE});
  makeMenuConnection(Action::SHOP, {Action::SHOP_BUY, Action::SHOP_SELL});
  makeMenuConnection(Action::QUEST, {Action::QUEST_ABANDON, Action::QUEST_FINISH});
  makeMenuConnection(Action::SPECIAL, {Action::SPECIAL_SUMMON, Action::SPECIAL_PICKPOCKET, Action::SPECIAL_POSSESS,
                                       Action::SPECIAL_READ, Action::SPECIAL_CALL});
  makeMenuConnection(Action::TRAVEL, {Action::TRAVEL_EXTERIOR, Action::TRAVEL_INTERIOR});

  makeMenuConnection(Action::SPECIAL_CALL, {Action::SPECIAL_CALL_REINFORCEMENT, Action::SPECIAL_CALL_ENEMY});
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
      // TODO: complete all cases
      switch (activeSubmenu) {
        case Action::ATTACK_CHARACTER:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.characters).parsed};
        case Action::ATTACK_BUILDING:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.buildings).parsed};
        case Action::ATTACK_STRUCTURE:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.structures).parsed};
        case Action::INVENTORY_PICKUP:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.floor).parsed};
        case Action::INVENTORY_DROP:
          return drop_item();
        case Action::INVENTORY_USE:
          return use_item();
        case Action::TRAVEL_INTERIOR:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.buildings).parsed};
        case Action::TRAVEL_EXTERIOR:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.exteriors).parsed};
        case Action::SPECIAL_PICKPOCKET: {
          const auto who = selectFromVector(snap.characters).parsed;
          const auto itemInput = selectFromVector(snap.ownedBy.find(who)->second);
          return Decision{activeSubmenu, snap.character.id, itemInput.parsed};
        }
        case Action::SPECIAL_POSSESS:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.characters).parsed};
        default:
          return Decision{Action::SKIP_TURN};
      }
    }
  }
}

Decision Player::use_item() {
  const auto cLen = snap.consumables.size();
  const auto eLen = snap.equippables.size();

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

void Player::makeMenuConnection(Action startSubmenu, const std::initializer_list<Action> &endSubmenus) {
  for (auto endSubmenu : endSubmenus) {
    decisionTree.emplace(endSubmenu, startSubmenu);
  }
}

template <typename T> ConsoleIn Player::selectFromVector(const std::vector<T> &vector) {
  view::input::generic(gameconstants::submenuInfo(activeSubmenu).prompt, vector);
  const auto in = controller::input::numeric(vector.size()) - 1;
  const auto parsedInput = vector[in].id;
  return ConsoleIn{static_cast<Quantity>(in), parsedInput};
}

template <typename T> Quantity Player::selectItemQuantity(const std::vector<T> &vector, ConsoleIn input) {
  const auto max = vector[input.raw].entity->quantity;
  if (max == 1) {
    return 1;
  }
  view::input::quantity(max);
  return controller::input::numeric(max);
}

} // namespace controller::brain
