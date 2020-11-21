//
// Created by nolasco on 21/06/20.
//

#pragma once

#include <memory>
#include <unordered_set>
#include <vector>

#include "datatypes/entity/Building.h"
#include "datatypes/entity/Character.h"
#include "datatypes/entity/Consumable.h"
#include "datatypes/entity/Equippable.h"
#include "datatypes/entity/Exterior.h"
#include "datatypes/entity/Structure.h"
#include "datatypes/entity/Team.h"

namespace view::stream {

constexpr auto STAT_LEN = 5;
constexpr auto NAME_LEN = 25;
constexpr auto ITEM_PADDING = 24;

// Base variables
std::ostream &operator<<(std::ostream &os, const Quantity &value);
std::ostream &operator<<(std::ostream &os, const Size &value);

// Entity Interface
std::ostream &operator<<(std::ostream &os, const entity::Entity &value);
std::ostream &operator<<(std::ostream &os, const entity::Item &value);
std::ostream &operator<<(std::ostream &os, const entity::Location &value);

// Entity
std::ostream &operator<<(std::ostream &os, const entity::Building &value);
std::ostream &operator<<(std::ostream &os, const entity::Character &value);
std::ostream &operator<<(std::ostream &os, const entity::Consumable &value);
std::ostream &operator<<(std::ostream &os, const entity::Equippable &value);
std::ostream &operator<<(std::ostream &os, const entity::Exterior &value);
std::ostream &operator<<(std::ostream &os, const entity::Structure &value);
std::ostream &operator<<(std::ostream &os, const entity::Team &value);

// Entity auxiliary
std::ostream &operator<<(std::ostream &os, const AttackType &value);
std::ostream &operator<<(std::ostream &os, const BuildingType &value);
std::ostream &operator<<(std::ostream &os, const ConsumableType &value);
std::ostream &operator<<(std::ostream &os, const EquippableType &value);
std::ostream &operator<<(std::ostream &os, const Ghost &value);
std::ostream &operator<<(std::ostream &os, const Info &value);
std::ostream &operator<<(std::ostream &os, const ItemEffect &value);
std::ostream &operator<<(std::ostream &os, const Occupation &value);
std::ostream &operator<<(std::ostream &os, const Race &value);
std::ostream &operator<<(std::ostream &os, const Stats &value);
std::ostream &operator<<(std::ostream &os, const StatusEffect &value);
std::ostream &operator<<(std::ostream &os, const StructureType &value);

// Containers
template <class T> std::ostream &operator<<(std::ostream &os, const std::shared_ptr<T> &value) {
  os << *value.get();
  return os;
}

template <class T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &container) {
  for (const auto &it : container) {
    os << it << ", ";
  }
  return os;
}

template <class T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &container) {
  for (const auto &it : container) {
    os << it << ", ";
  }
  return os;
}

} // namespace view::stream
