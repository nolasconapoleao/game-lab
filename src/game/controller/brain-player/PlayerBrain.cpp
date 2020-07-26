//
// Created by nolasco on 10/06/20.
//

#include "PlayerBrain.h"

#include <controller/brain-player/input/Input.h>
#include <libs/constants/gameconstants.h>

#include "view/Printer.h"
#include "view/input-prompt/Input-Prompter.h"

namespace controller::brain {

player::player() : snap(snap), active(Action::UNDEFINED) {
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

Decision player::think(const Snapshot &snapshot) {
  active = Action::UNDEFINED;
  snap = snapshot;

  // TODO: Change to have time termination
  // TODO: Change to disable invalid options
  while (true) {
    view::printer::printScreen(snapshot);

    if (!gameconstants::stateInfo(active).terminal) {
      selectSubstate();
    } else {
      Decision decision;
      switch (active) {
        case Action::SKIP_TURN:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::MENU_SAVE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::MENU_TUTORIAL:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::MENU_TERMINATE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::ATTACK_CHARACTER:
          decision = Decision{active, snap.character.id, selectFromVector(snap.characters)};
          break;
        case Action::ATTACK_BUILDING:
          decision = Decision{active, snap.character.id, selectFromVector(snap.buildings)};
          break;
        case Action::ATTACK_STRUCTURE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::INVENTORY_PICKUP:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::INVENTORY_DROP:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::INVENTORY_USE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::TEAM_CREATE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::TEAM_DISBAND:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::TEAM_TRADE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::TEAM_KICK:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::TEAM_INVITE:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SHOP_BUY:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SHOP_SELL:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::QUEST_ABANDON:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::QUEST_FINISH:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::TRAVEL_INTERIOR:
          decision = Decision{active, snap.character.id, selectFromVector(snap.buildings)};
          break;
        case Action::TRAVEL_EXTERIOR:
          decision = Decision{active, snap.character.id, selectFromVector(snap.exteriors)};
          break;
        case Action::SPECIAL_SUMMON:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_PICKPOCKET:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_POSSESS:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_READ:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_CALL_REINFORCEMENT:
          decision = Decision{Action::SKIP_TURN};
          break;
        case Action::SPECIAL_CALL_ENEMY:
          decision = Decision{Action::SKIP_TURN};
          break;
      }

      if (gameconstants::stateInfo(active).terminal) {
        return decision;
      }
    }
  }
}

void player::selectSubstate() {
  std::vector<PlayerState> options;
  std::string validInput = "";
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

void player::makeBranch(Action start, const std::initializer_list<Action> &end) {
  for (auto it : end) {
    decisionTree.emplace(it, start);
  }
}

template <typename T> ResourceId player::selectFromVector(const std::vector<T> &vector) {
  if (vector.size() == 0) {
    view::input::invalid(gameconstants::stateInfo(active).prompt);
    active = Action::UNDEFINED;
    return 0;
  }

  view::input::generic(gameconstants::stateInfo(active).prompt, vector);
  const auto in = controller::input::numeric(vector.size()) - 1;
  const auto parsedInput = vector[in].id;
  return parsedInput;
}

} // namespace controller::brain
