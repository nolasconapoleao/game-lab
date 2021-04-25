//
// Created by nolasco on 30/11/20.
//

#pragma once

#include "datatypes/entity/Building.h"
#include "datatypes/entity/Character.h"
#include "datatypes/entity/Consumable.h"
#include "datatypes/entity/Equippable.h"
#include "datatypes/entity/Exterior.h"
#include "datatypes/entity/Structure.h"
#include "datatypes/entity/Team.h"

// Base variables
bool compare(const Size &lhs, const Size &rhs);

// Entity Interface
bool compare(const entity::Entity &lhs, const entity::Entity &rhs);
bool compare(const entity::Item &lhs, const entity::Item &rhs);
bool compare(const entity::Location &lhs, const entity::Location &rhs);

// Entity
bool compare(const entity::Building &lhs, const entity::Building &rhs);
bool compare(const entity::Character &lhs, const entity::Character &rhs);
bool compare(const entity::Consumable &lhs, const entity::Consumable &rhs);
bool compare(const entity::Equippable &lhs, const entity::Equippable &rhs);
bool compare(const entity::Exterior &lhs, const entity::Exterior &rhs);
bool compare(const entity::Structure &lhs, const entity::Structure &rhs);
bool compare(const entity::Team &lhs, const entity::Team &rhs);

// Entity auxiliary
bool compare(const Info &lhs, const Info &rhs);
bool compare(const ItemEffect &lhs, const ItemEffect &rhs);
bool compare(const Stats &lhs, const Stats &rhs);

// Declaration
bool compare(const Size &lhs, const Size &rhs) {
  return ((lhs.width == rhs.width) && (lhs.height == rhs.height));
}

bool compare(const entity::Entity &lhs, const entity::Entity &rhs) {
  return (lhs.name == rhs.name);
}

bool compare(const entity::Item &lhs, const entity::Item &rhs) {
  return (compare(static_cast<const entity::Entity &>(lhs), static_cast<const entity::Entity &>(rhs))
          && compare(lhs.effect, rhs.effect) && (lhs.quantity == rhs.quantity) && (lhs.unitWeight == rhs.unitWeight)
          && (lhs.unitPrice == rhs.unitPrice));
}

bool compare(const entity::Location &lhs, const entity::Location &rhs) {
  return (compare(static_cast<const entity::Entity &>(lhs), static_cast<const entity::Entity &>(rhs))
          && compare(lhs.size, rhs.size));
}

bool compare(const entity::Building &lhs, const entity::Building &rhs) {
  return (compare(static_cast<const entity::Location &>(lhs), static_cast<const entity::Location &>(rhs))
          && (lhs.type == rhs.type) && (lhs.health == rhs.health) && (lhs.floors == rhs.floors));
}

bool compare(const entity::Character &lhs, const entity::Character &rhs) {
  return (compare(static_cast<const entity::Entity &>(lhs), static_cast<const entity::Entity &>(rhs))
          && compare(lhs.base, rhs.base) && compare(lhs.temp, rhs.temp) && compare(lhs.info, rhs.info)
          && (lhs.effects == rhs.effects));
}

bool compare(const entity::Consumable &lhs, const entity::Consumable &rhs) {
  return (compare(static_cast<const entity::Item &>(lhs), static_cast<const entity::Item &>(rhs))
          && (lhs.type == rhs.type) && (lhs.duration == rhs.duration) && (lhs.consumed == rhs.consumed));
}

bool compare(const entity::Equippable &lhs, const entity::Equippable &rhs) {
  return (compare(static_cast<const entity::Item &>(lhs), static_cast<const entity::Item &>(rhs))
          && (lhs.type == rhs.type) && (lhs.uses == rhs.uses) && (lhs.equipped == rhs.equipped));
}

bool compare(const entity::Exterior &lhs, const entity::Exterior &rhs) {
  return (compare(static_cast<const entity::Location &>(lhs), static_cast<const entity::Location &>(rhs)));
}

bool compare(const entity::Structure &lhs, const entity::Structure &rhs) {
  return (compare(static_cast<const entity::Entity &>(lhs), static_cast<const entity::Entity &>(rhs))
          && (lhs.type == rhs.type) && (lhs.health == rhs.health) && compare(lhs.size, rhs.size));
}

bool compare(const entity::Team &lhs, const entity::Team &rhs) {
  return (compare(static_cast<const entity::Entity &>(lhs), static_cast<const entity::Entity &>(rhs)));
}

bool compare(const Info &lhs, const Info &rhs) {
  return ((lhs.cash == rhs.cash) && (lhs.ghost == rhs.ghost) && (lhs.race == rhs.race)
          && (lhs.attackType == rhs.attackType) && (lhs.occupation == rhs.occupation));
}

bool compare(const ItemEffect &lhs, const ItemEffect &rhs) {
  return ((lhs.hp == rhs.hp) && (lhs.atk == rhs.atk) && (lhs.def == rhs.def) && (lhs.mAtk == rhs.mAtk)
          && (lhs.mDef == rhs.mDef) && (lhs.spd == rhs.spd) && (lhs.inte == rhs.inte) && (lhs.acc == rhs.acc)
          && (lhs.ste == rhs.ste) && (lhs.mana == rhs.mana) && (lhs.ran == rhs.ran));
}

bool compare(const Stats &lhs, const Stats &rhs) {
  return (compare(static_cast<const ItemEffect &>(lhs), static_cast<const ItemEffect &>(rhs)) && (lhs.mhp == rhs.mhp)
          && (lhs.cst == rhs.cst) && (lhs.lvl == rhs.lvl) && (lhs.xp == rhs.xp));
}
