//
// Created by nolasco on 10/06/20.
//

#include "PlayerBrain.h"

#include "input/capture/Input-Capture.h"
#include "input/print/Input-Prompter.h"
#include "libs/constants/gameconstants.h"
#include "view/Printer.h"

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

  bool firstInteraction{true};

  // TODO(nn): Change to have time termination
  while (true) {
    view::printer::printScreen(snapshot, activeSubmenu, !firstInteraction);
    firstInteraction = false;

    if (!gameconstants::submenuInfo(activeSubmenu).terminal) {
      selectSubmenu();
    } else {
      switch (activeSubmenu) {
        case Action::ATTACK_CHARACTER:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.characters).parsed};
        case Action::ATTACK_BUILDING:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.buildings).parsed};
        case Action::ATTACK_STRUCTURE:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.structures).parsed};
        case Action::INVENTORY_PICKUP:
          return Decision{activeSubmenu, snap.character.id, selectFromVector(snap.floor).parsed};
        case Action::INVENTORY_DROP: {
          const auto item = selectFromItems();
          const auto quantity = selectItemQuantity(item.entity->quantity);
          return Decision{activeSubmenu, item.id, snap.location.id, quantity};
        }
        case Action::INVENTORY_USE: {
          const auto item = selectFromItems();
          return Decision{activeSubmenu, snap.character.id, item.id};
        }
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

DbEntry<entity::Item> &Player::selectFromItems() {
  const auto cLen = snap.consumables.size();
  const auto eLen = snap.equippables.size();

  ::input::prompt::items(gameconstants::submenuInfo(activeSubmenu).prompt, snap);
  const auto in = controller::input::numeric(eLen + cLen);
  if (in <= cLen) {
    return reinterpret_cast<DbEntry<entity::Item> &>(snap.consumables[in - 1]);
  } else {
    return reinterpret_cast<DbEntry<entity::Item> &>(snap.equippables[in - cLen - 1]);
  }
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

  ::input::prompt::playerMenu(options);
  const auto in = controller::input::alphanum(validInput);
  activeSubmenu = options[validInput.find(in)].action;
}

void Player::makeMenuConnection(Action startSubmenu, const std::initializer_list<Action> &endSubmenus) {
  for (auto endSubmenu : endSubmenus) {
    decisionTree.emplace(endSubmenu, startSubmenu);
  }
}

template <typename T> ConsoleIn Player::selectFromVector(const std::vector<T> &vector) {
  ::input::prompt::generic(gameconstants::submenuInfo(activeSubmenu).prompt, vector);
  const auto in = controller::input::numeric(vector.size()) - 1;
  const auto parsedInput = vector[in].id;
  return ConsoleIn{static_cast<Quantity>(in), parsedInput};
}

Quantity Player::selectItemQuantity(const Quantity upperBound) {
  if (upperBound == 1) {
    return 1;
  }
  ::input::prompt::quantity(upperBound);
  return controller::input::numeric(upperBound);
}

} // namespace controller::brain
