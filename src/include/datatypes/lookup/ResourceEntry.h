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

struct EntityEntry {
  ResourceId id;
  std::shared_ptr<entity::Entity> entity;
};

struct CharacterEntry {
  CharacterId id;
  std::shared_ptr<entity::Character> entity;
};

struct ItemEntry {
  ItemId id;
  std::shared_ptr<entity::Item> entity;
};

struct ConsumableEntry {
  ItemId id;
  std::shared_ptr<entity::Consumable> entity;
};

struct EquippableEntry {
  ItemId id;
  std::shared_ptr<entity::Equippable> entity;
};

struct LocationEntry {
  LocationId id;
  std::shared_ptr<entity::Location> entity;
};

struct ExteriorEntry {
  LocationId id;
  std::shared_ptr<entity::Exterior> entity;
};

struct BuildingEntry {
  LocationId id;
  std::shared_ptr<entity::Building> entity;
};

struct StructureEntry {
  StructureId id;
  std::shared_ptr<entity::Structure> entity;
};

struct TeamEntry {
  TeamId id;
  std::shared_ptr<entity::Team> entity;
};

struct Snapshot {
  CharacterEntry character;
  LocationEntry location;
  std::vector<ConsumableEntry> consumables;
  std::vector<EquippableEntry> equippables;
  std::vector<CharacterEntry> characters;
  std::vector<StructureEntry> structures;
  std::vector<BuildingEntry> buildings;
  std::vector<ExteriorEntry> exteriors;
  std::vector<ItemEntry> floor;
  std::map<CharacterId, std::vector<ItemEntry>> ownedBy;
};
