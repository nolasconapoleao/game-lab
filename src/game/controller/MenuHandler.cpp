//
// Created by nolasco on 25/11/20.
//

#include "MenuHandler.h"

namespace controller {

// TODO: complete all cases
bool MenuHandler::shouldDisplaySubmenu(const Snapshot &snapshot, const Action &submmenu) {
  switch (submmenu) {
    case Action::ATTACK:
      return shouldDisplaySubmenu(snapshot, Action::ATTACK_CHARACTER)
             || shouldDisplaySubmenu(snapshot, Action::ATTACK_BUILDING)
             || shouldDisplaySubmenu(snapshot, Action::ATTACK_STRUCTURE);
    case Action::ATTACK_CHARACTER:
      return !snapshot.characters.empty();
    case Action::ATTACK_BUILDING:
      return !snapshot.buildings.empty();
    case Action::ATTACK_STRUCTURE:
      return !snapshot.structures.empty();
    case Action::INVENTORY:
      return shouldDisplaySubmenu(snapshot, Action::INVENTORY_PICKUP)
             || shouldDisplaySubmenu(snapshot, Action::INVENTORY_DROP)
             || shouldDisplaySubmenu(snapshot, Action::INVENTORY_USE);
    case Action::INVENTORY_PICKUP:
      return !snapshot.floor.empty();
    case Action::INVENTORY_DROP:
      return !snapshot.consumables.empty() || !snapshot.equippables.empty();
    case Action::INVENTORY_USE:
      return !snapshot.consumables.empty() || !snapshot.equippables.empty();
    case Action::TEAM:
      return !ongoingCombat(snapshot)
             && (shouldDisplaySubmenu(snapshot, Action::TEAM_CREATE)
                 || shouldDisplaySubmenu(snapshot, Action::TEAM_DISBAND)
                 || shouldDisplaySubmenu(snapshot, Action::TEAM_TRADE)
                 || shouldDisplaySubmenu(snapshot, Action::TEAM_KICK)
                 || shouldDisplaySubmenu(snapshot, Action::TEAM_INVITE));
    case Action::TEAM_CREATE:
      [[fallthrough]];
    case Action::TEAM_DISBAND:
      [[fallthrough]];
    case Action::TEAM_TRADE:
      [[fallthrough]];
    case Action::TEAM_KICK:
      [[fallthrough]];
    case Action::TEAM_INVITE:
      return !ongoingCombat(snapshot);
    case Action::SHOP:
      return !ongoingCombat(snapshot)
             && (shouldDisplaySubmenu(snapshot, Action::SHOP_BUY) || shouldDisplaySubmenu(snapshot, Action::SHOP_SELL));
    case Action::SHOP_BUY:
      [[fallthrough]];
    case Action::SHOP_SELL:
      return snapshotUtilities.shopkeeperAvailable(snapshot);
    case Action::QUEST:
      return (shouldDisplaySubmenu(snapshot, Action::QUEST_ABANDON)
              || shouldDisplaySubmenu(snapshot, Action::QUEST_FINISH));
    case Action::QUEST_ABANDON:
      [[fallthrough]];
    case Action::QUEST_FINISH:
      return true;
    case Action::TRAVEL:
      return !ongoingCombat(snapshot);
    case Action::TRAVEL_EXTERIOR:
      return !snapshot.exteriors.empty();
    case Action::TRAVEL_INTERIOR:
      return !snapshot.buildings.empty();
    case Action::SPECIAL:
      return !ongoingCombat(snapshot)
             && (shouldDisplaySubmenu(snapshot, Action::SPECIAL_SUMMON)
                 || shouldDisplaySubmenu(snapshot, Action::SPECIAL_PICKPOCKET)
                 || shouldDisplaySubmenu(snapshot, Action::SPECIAL_POSSESS)
                 || shouldDisplaySubmenu(snapshot, Action::SPECIAL_READ)
                 || shouldDisplaySubmenu(snapshot, Action::SPECIAL_CALL)
                 || shouldDisplaySubmenu(snapshot, Action::SPECIAL_CALL_REINFORCEMENT)
                 || shouldDisplaySubmenu(snapshot, Action::SPECIAL_CALL_ENEMY));
    case Action::SPECIAL_SUMMON:
      [[fallthrough]];
    case Action::SPECIAL_PICKPOCKET:
      [[fallthrough]];
    case Action::SPECIAL_POSSESS:
      [[fallthrough]];
    case Action::SPECIAL_READ:
      return true;
    case Action::SPECIAL_CALL:
      return snapshotUtilities.phoneboothAvailable(snapshot);
    case Action::SPECIAL_CALL_REINFORCEMENT:
      return snapshotUtilities.phoneboothAvailable(snapshot);
    case Action::SPECIAL_CALL_ENEMY:
      return snapshotUtilities.phoneboothAvailable(snapshot);
    default:
      return true;
  }
}

bool MenuHandler::ongoingCombat(const Snapshot & /*snapshot*/) {
  // TODO: Current implementation does not recognize combat situation
  return false;
}

} // namespace controller
