//
// Created by nolasco on 30/06/20.
//

#include "datatypes/controller/Action.h"
#include "datatypes/controller/MenuState.h"
#include "datatypes/entity-aux/Stats.h"
#include "datatypes/factory/CreationSpecs.h"
#include "datatypes/factory/ThreatLevel.h"

namespace gameconstants {

constexpr Stats minimalStats() {
  Stats result;
  result.hp = 8;
  result.atk = 0;
  result.def = 0;
  result.mAtk = 0;
  result.mDef = 0;
  result.spd = 2;
  result.inte = 3;
  result.acc = 2;
  result.ste = 0;
  result.ran = 1;
  result.mana = 0;
  result.mhp = 8;
  result.cst = 10;
  return result;
}

constexpr CreationSpecs creationSpecs(const ThreatLevel level) {
  CreationSpecs specs;
  switch (level) {
    case ThreatLevel::SCARECROW:
      specs.stats_multiplier = 1;
      specs.num_characters = 1;
      specs.num_character_consumables = 0;
      specs.num_character_equippables = 0;
      specs.num_exterior_consumables = 0;
      specs.num_exterior_equippables = 0;
      specs.num_exteriors = 1;
      specs.num_buildings = 1;
      specs.num_structures = 1;
      break;
    case ThreatLevel::NOVICE:
      specs.stats_multiplier = 2;
      specs.num_characters = 2;
      specs.num_character_consumables = 1;
      specs.num_character_equippables = 1;
      specs.num_exterior_consumables = 1;
      specs.num_exterior_equippables = 0;
      specs.num_exteriors = 1;
      specs.num_buildings = 2;
      specs.num_structures = 2;
      break;
    case ThreatLevel::ACE:
      specs.stats_multiplier = 5;
      specs.num_characters = 5;
      specs.num_character_consumables = 2;
      specs.num_character_equippables = 2;
      specs.num_exterior_consumables = 2;
      specs.num_exterior_equippables = 1;
      specs.num_exteriors = 3;
      specs.num_buildings = 2;
      specs.num_structures = 2;
      break;
    case ThreatLevel::VETERAN:
      specs.stats_multiplier = 10;
      specs.num_characters = 5;
      specs.num_character_consumables = 3;
      specs.num_character_equippables = 3;
      specs.num_exterior_consumables = 3;
      specs.num_exterior_equippables = 2;
      specs.num_exteriors = 2;
      specs.num_buildings = 3;
      specs.num_structures = 2;
      break;
    case ThreatLevel::MONSTER:
      specs.stats_multiplier = 20;
      specs.num_characters = 12;
      specs.num_character_consumables = 4;
      specs.num_character_equippables = 4;
      specs.num_exterior_consumables = 5;
      specs.num_exterior_equippables = 1;
      specs.num_exteriors = 3;
      specs.num_buildings = 3;
      specs.num_structures = 2;
      break;
    case ThreatLevel::GOD:
      specs.stats_multiplier = 50;
      specs.num_characters = 20;
      specs.num_character_consumables = 5;
      specs.num_character_equippables = 5;
      specs.num_exterior_consumables = 5;
      specs.num_exterior_equippables = 5;
      specs.num_exteriors = 3;
      specs.num_buildings = 4;
      specs.num_structures = 2;
      break;
  }
  return specs;
}

constexpr MenuState submenuInfo(Action action) {
  switch (action) {
    case Action::SKIP_TURN:
      return {action, 'e', "Skip turn", true};
    case Action::MENU:
      return {action, 'm', "Menu"};
    case Action::MENU_SAVE:
      return {action, 's', "Save", true};
    case Action::MENU_TUTORIAL:
      return {action, 't', "Tutorial", true};
    case Action::MENU_TERMINATE:
      return {action, 'x', "Terminate", true};
    case Action::ATTACK:
      return {action, 'a', "Attack"};
    case Action::ATTACK_CHARACTER:
      return {action, 'c', "Attack character", true};
    case Action::ATTACK_BUILDING:
      return {action, 'b', "Attack building", true};
    case Action::ATTACK_STRUCTURE:
      return {action, 's', "Attack structure", true};
    case Action::INVENTORY:
      return {action, 'i', "Inventory"};
    case Action::INVENTORY_PICKUP:
      return {action, 'p', "Inventory pickup", true};
    case Action::INVENTORY_DROP:
      return {action, 'd', "Inventory drop", true};
    case Action::INVENTORY_USE:
      return {action, 'u', "Inventory use", true};
    case Action::TEAM:
      return {action, 't', "Team"};
    case Action::TEAM_CREATE:
      return {action, 'c', "Create team", true};
    case Action::TEAM_DISBAND:
      return {action, 'd', "Disband team", true};
    case Action::TEAM_TRADE:
      return {action, 't', "Trade with team member", true};
    case Action::TEAM_KICK:
      return {action, 'k', "Kick team member", true};
    case Action::TEAM_INVITE:
      return {action, 'i', "Invite to team", true};
    case Action::SHOP:
      return {action, 's', "Shop"};
    case Action::SHOP_BUY:
      return {action, 'b', "Buy", true};
    case Action::SHOP_SELL:
      return {action, 's', "Sell", true};
    case Action::QUEST:
      return {action, 'q', "Quest"};
    case Action::QUEST_ABANDON:
      return {action, 'd', "Abandon quest", true};
    case Action::QUEST_FINISH:
      return {action, 'f', "Finish quest", true};
    case Action::TRAVEL:
      return {action, 'w', "Travel"};
    case Action::TRAVEL_INTERIOR:
      return {action, 'b', "Enter building", true};
    case Action::TRAVEL_EXTERIOR:
      return {action, 'e', "Travel to", true};
    case Action::SPECIAL:
      return {action, '*', "Special"};
    case Action::SPECIAL_SUMMON:
      return {action, 'b', "Summon", true};
    case Action::SPECIAL_PICKPOCKET:
      return {action, 'o', "Pickpocket", true};
    case Action::SPECIAL_POSSESS:
      return {action, 'g', "Possess", true};
    case Action::SPECIAL_READ:
      return {action, 'r', "Read", true};
    case Action::SPECIAL_CALL:
      return {action, 'c', "Call"};
    case Action::SPECIAL_CALL_REINFORCEMENT:
      return {action, 'r', "Call reinforcement", true};
    case Action::SPECIAL_CALL_ENEMY:
      return {action, 't', "Call enemy", true};
    default:
      return {action, ' ', ""};
  }
}

} // namespace gameconstants
