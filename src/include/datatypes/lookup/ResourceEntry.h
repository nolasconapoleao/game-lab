//
// Created by nolasco on 27/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <vector>

#include "datatypes/entity/Building.h"
#include "datatypes/entity/Character.h"
#include "datatypes/entity/Consumable.h"
#include "datatypes/entity/Equippable.h"
#include "datatypes/entity/Exterior.h"
#include "datatypes/entity/Structure.h"
#include "datatypes/entity/Team.h"
#include "datatypes/lookup/ResourceType.h"
#include "interface/entity/Item.h"
#include "interface/entity/Location.h"

/// @brief Template Entry structure
template <class T> class DbEntry {
public:
  /// @brief Entity Id for database search.
  EntityId id;
  /// @brief Entity object information.
  std::shared_ptr<T> entity;
};

/// @brief Game snapshot for decision making.
struct Snapshot {
  /// @brief current character.
  DbEntry<entity::Character> character;
  /// @brief current location.
  DbEntry<entity::Location> location;
  /// @brief internally available consumables.
  std::vector<DbEntry<entity::Consumable>> consumables;
  /// @brief internally available equippables.
  std::vector<DbEntry<entity::Equippable>> equippables;
  /// @brief characters in current location.
  std::vector<DbEntry<entity::Character>> characters;
  /// @brief structures in current location.
  std::vector<DbEntry<entity::Structure>> structures;
  /// @brief buildings in current location.
  std::vector<DbEntry<entity::Building>> buildings;
  /// @brief exteriors in current location.
  std::vector<DbEntry<entity::Exterior>> exteriors;
  /// @brief items in the floor.
  std::vector<DbEntry<entity::Item>> floor;
  /// @brief items owned by characters on the current location.
  std::map<CharacterId, std::vector<DbEntry<entity::Item>>> ownedBy;
};
