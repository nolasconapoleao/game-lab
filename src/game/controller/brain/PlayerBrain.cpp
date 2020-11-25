//
// Created by nolasco on 10/06/20.
//

#include "PlayerBrain.h"

#include <controller/input/Input.h>
#include <libs/constants/gameconstants.h>

#include "view/Printer.h"
#include "view/input-prompt/Input-Prompter.h"

namespace controller::brain {

Player::Player() : active(Action::UNDEFINED) {
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
  active = Action::UNDEFINED;
  snap = snapshot;

  // TODO: Change to have time termination
  // TODO: Change to disable invalid options
  while (true) {
    view::printer::printScreen(snapshot);

    if (!gameconstants::stateInfo(active).terminal) {
      selectSubstate();
    } else {
      Decision decision{};
      switch (active) {
        case Action::ATTACK_CHARACTER:
          decision = Decision{active, snap.character.id, selectFromVector(snap.characters).parsed};
          break;
        case Action::ATTACK_BUILDING:
          decision = Decision{active, snap.character.id, selectFromVector(snap.buildings).parsed};
          break;
        case Action::ATTACK_STRUCTURE:
          decision = Decision{active, snap.character.id, selectFromVector(snap.structures).parsed};
          break;
        case Action::INVENTORY_PICKUP:
          decision = Decision{active, snap.character.id, selectFromVector(snap.floor).parsed};
          break;
        case Action::INVENTORY_DROP:
          decision = drop_item();
          break;
        case Action::INVENTORY_USE:
          decision = use_item();
          break;
        case Action::TRAVEL_INTERIOR:
          decision = Decision{active, snap.character.id, selectFromVector(snap.buildings).parsed};
          break;
        case Action::TRAVEL_EXTERIOR:
          decision = Decision{active, snap.character.id, selectFromVector(snap.exteriors).parsed};
          break;
        case Action::SPECIAL_SUMMON:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_PICKPOCKET: {
          const auto who = selectFromVector(snap.characters).parsed;
          const auto itemInput = selectFromVector(snap.ownedBy.find(who)->second);
          decision = Decision{active, snap.character.id, itemInput.parsed};
          break;
        }
        case Action::SPECIAL_POSSESS:
          decision = Decision{active, snap.character.id, selectFromVector(snap.buildings).parsed};
          break;
        case Action::SKIP_TURN:
          [[fallthrough]];
        default:
          decision = Decision{Action::SKIP_TURN};
          break;
      }

      if (gameconstants::stateInfo(active).terminal) {
        return decision;
      }
    }
  }
}

Decision Player::use_item() {
  const auto cLen = snap.consumables.size();
  const auto eLen = snap.equippables.size();
  if (cLen == 0 && eLen == 0) {
    view::input::invalid(gameconstants::stateInfo(active).prompt);
    active = Action::UNDEFINED;
    return Decision{Action::UNDEFINED};
  }

  view::input::items(gameconstants::stateInfo(active).prompt, snap);
  ResourceId parsedInput{0};
  const auto in = controller::input::numeric(eLen + cLen);
  if (in <= cLen) {
    parsedInput = snap.consumables[in - 1].id;
  } else {
    parsedInput = snap.equippables[in - cLen - 1].id;
  }
  return Decision{active, snap.character.id, parsedInput};
}

Decision Player::drop_item() {
  const auto cLen = snap.consumables.size();
  const auto eLen = snap.equippables.size();
  if (cLen == 0 && eLen == 0) {
    view::input::invalid(gameconstants::stateInfo(active).prompt);
    active = Action::UNDEFINED;
    return Decision{Action::UNDEFINED};
  }

  view::input::items(gameconstants::stateInfo(active).prompt, snap);
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
  return Decision{active, parsedInput, snap.location.id, quantity};
}

void Player::selectSubstate() {
  std::vector<MenuState> options;
  std::string validInput;
  for (const auto &[start, end] : decisionTree) {
    if (end == active) {
      const auto &stateInfo = gameconstants::stateInfo(start);
      options.emplace_back(stateInfo);
      validInput += stateInfo.transition;
    }
  };

  view::input::playerMenu(options);
  const auto in = controller::input::alphanum(validInput);
  active = options[validInput.find(in)].action;
}

void Player::makeBranch(Action start, const std::initializer_list<Action> &end) {
  for (auto it : end) {
    decisionTree.emplace(it, start);
  }
}

template <typename T> ConsoleIn Player::selectFromVector(const std::vector<T> &vector) {
  if (vector.empty()) {
    view::input::invalid(gameconstants::stateInfo(active).prompt);
    active = Action::UNDEFINED;
    return {0, 0};
  }

  view::input::generic(gameconstants::stateInfo(active).prompt, vector);
  const auto in = controller::input::numeric(vector.size()) - 1;
  const auto parsedInput = vector[in].id;
  return ConsoleIn{static_cast<Quantity>(in), parsedInput};
}

template <typename T> Quantity Player::selectItemQuantity(const std::vector<T> &vector, ConsoleIn input) {
  if (vector.empty()) {
    view::input::invalid("No items available!");
    active = Action::UNDEFINED;
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
