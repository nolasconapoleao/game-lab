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

// TODO: Create Entry template

/// @brief Character Entry structure
struct CharacterEntry {
  /// @brief Character Id for database search.
  CharacterId id;
  /// @brief Character object information.
  std::shared_ptr<entity::Character> entity;
};

/// @brief Item Entry structure
struct ItemEntry {
  /// @brief Item Id for database search.
  ItemId id;
  /// @brief Item object information.
  std::shared_ptr<entity::Item> entity;
};

/// @brief Consumable Entry structure
struct ConsumableEntry {
  /// @brief Consumable Id for database search.
  ItemId id;
  /// @brief Consumable object information.
  std::shared_ptr<entity::Consumable> entity;
};

/// @brief Equippable Entry structure
struct EquippableEntry {
  /// @brief Equippable Id for database search.
  ItemId id;
  /// @brief Equippable object information.
  std::shared_ptr<entity::Equippable> entity;
};

/// @brief Location Entry structure
struct LocationEntry {
  /// @brief Location Id for database search.
  LocationId id;
  /// @brief Location object information.
  std::shared_ptr<entity::Location> entity;
};

/// @brief Exterior Entry structure
struct ExteriorEntry {
  /// @brief Exterior Id for database search.
  LocationId id;
  /// @brief Exterior object information.
  std::shared_ptr<entity::Exterior> entity;
};

/// @brief Building Entry structure
struct BuildingEntry {
  /// @brief Building Id for database search.
  LocationId id;
  /// @brief Building object information.
  std::shared_ptr<entity::Building> entity;
};

/// @brief Structure Entry structure
struct StructureEntry {
  /// @brief Structure Id for database search.
  StructureId id;
  /// @brief Structure object information.
  std::shared_ptr<entity::Structure> entity;
};

/// @brief Game snapshot for decision making.
struct Snapshot {
  /// @brief current character.
  CharacterEntry character;
  /// @brief current location.
  LocationEntry location;
  /// @brief internally available consumables.
  std::vector<ConsumableEntry> consumables;
  /// @brief internally available equippables.
  std::vector<EquippableEntry> equippables;
  /// @brief characters in current location.
  std::vector<CharacterEntry> characters;
  /// @brief structures in current location.
  std::vector<StructureEntry> structures;
  /// @brief buildings in current location.
  std::vector<BuildingEntry> buildings;
  /// @brief exteriors in current location.
  std::vector<ExteriorEntry> exteriors;
  /// @brief items in the floor.
  std::vector<ItemEntry> floor;
  /// @brief items owned by characters on the current location.
  std::map<CharacterId, std::vector<ItemEntry>> ownedBy;
};
