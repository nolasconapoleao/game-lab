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

  makeBranch(Action::SPECIAL_CALL, {Action::SPECIAL_CALL_REINFORCEMENT, Action::SPECIAL_CALL_ENEMY});
}

Decision player::think(const Snapshot &snapshot) {
  active = Action::UNDEFINED;
  snap = snapshot;

  while (true) { // TODO: Change to have time termination
    view::printer::printScreen(snapshot);
    switch (active) {
      case Action::UNDEFINED:
        [[fallthrough]];
      case Action::MENU:
        [[fallthrough]];
      case Action::ATTACK:
        [[fallthrough]];
      case Action::INVENTORY:
        [[fallthrough]];
      case Action::TEAM:
        [[fallthrough]];
      case Action::SHOP:
        [[fallthrough]];
      case Action::QUEST:
        [[fallthrough]];
      case Action::SPECIAL:
        [[fallthrough]];
      case Action::SPECIAL_CALL:
        selectSubstate();
        break;
      case Action::SKIP_TURN:
        return Decision{Action::SKIP_TURN};
      case Action::MENU_SAVE:
        return Decision{Action::SKIP_TURN};
      case Action::MENU_TUTORIAL:
        return Decision{Action::SKIP_TURN};
      case Action::MENU_TERMINATE:
        return Decision{Action::SKIP_TURN};
      case Action::ATTACK_CHARACTER:
        return attack_characters();
      case Action::ATTACK_BUILDING:
        return Decision{Action::SKIP_TURN};
      case Action::ATTACK_STRUCTURE:
        return Decision{Action::SKIP_TURN};
      case Action::INVENTORY_PICKUP:
        return Decision{Action::SKIP_TURN};
      case Action::INVENTORY_DROP:
        return Decision{Action::SKIP_TURN};
      case Action::INVENTORY_USE:
        return Decision{Action::SKIP_TURN};
      case Action::TEAM_CREATE:
        return Decision{Action::SKIP_TURN};
      case Action::TEAM_DISBAND:
        return Decision{Action::SKIP_TURN};
      case Action::TEAM_TRADE:
        return Decision{Action::SKIP_TURN};
      case Action::TEAM_KICK:
        return Decision{Action::SKIP_TURN};
      case Action::TEAM_INVITE:
        return Decision{Action::SKIP_TURN};
      case Action::SHOP_BUY:
        return Decision{Action::SKIP_TURN};
      case Action::SHOP_SELL:
        return Decision{Action::SKIP_TURN};
      case Action::QUEST_ABANDON:
        return Decision{Action::SKIP_TURN};
      case Action::QUEST_FINISH:
        return Decision{Action::SKIP_TURN};
      case Action::TRAVEL:
        return travel();
      case Action::SPECIAL_SUMMON:
        return Decision{Action::SKIP_TURN};
      case Action::SPECIAL_PICKPOCKET:
        return Decision{Action::SKIP_TURN};
      case Action::SPECIAL_POSSESS:
        return Decision{Action::SKIP_TURN};
      case Action::SPECIAL_READ:
        return Decision{Action::SKIP_TURN};
      case Action::SPECIAL_CALL_REINFORCEMENT:
        return Decision{Action::SKIP_TURN};
      case Action::SPECIAL_CALL_ENEMY:
        return Decision{Action::SKIP_TURN};
    }
  }
}

Decision player::travel() {
  view::input::travel(snap);
  const auto bLen = snap.buildings.size();
  const auto eLen = snap.exteriors.size();
  const auto in = controller::input::numeric(bLen + eLen) - 1;
  const auto destination = (in > bLen - 1) ? snap.buildings[in].id : snap.exteriors[in - bLen].id;
  return Decision{Action::TRAVEL, snap.character.id, destination};
}

Decision player::attack_characters() {
  view::input::generic(gameconstants::stateInfo(active).prompt, snap.characters);
  const auto in = controller::input::numeric(snap.characters.size()) - 1;
  const auto destination = snap.characters[in].id;
  return Decision{active, snap.character.id, destination};
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

} // namespace controller::brain
