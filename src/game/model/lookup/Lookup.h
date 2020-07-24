//
// Created by nolasco on 07/06/20.
//

#pragma once

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

namespace model {

// Forward declaration
class World;

class Lookup {
public:
  Lookup(const std::shared_ptr<World> &world);
  const std::vector<ItemEntry> itemsIn(const ResourceId resourceId);
  const std::vector<ConsumableEntry> consumablesIn(const ResourceId resourceId);
  const std::vector<EquippableEntry> equippablesIn(const ResourceId resourceId);
  const std::vector<CharacterEntry> charactersIn(const LocationId locationId);
  const std::vector<StructureEntry> structuresIn(const LocationId locationId);
  const std::vector<ExteriorEntry> neighbourExteriors(const LocationId locationId);
  const std::vector<BuildingEntry> neighbourBuildings(const LocationId locationId);
  const std::vector<LocationEntry> neighbourLocations(const LocationId locationId);
  const std::vector<LocationEntry> neighboursEndingIn(const LocationId locationId);

  const std::vector<LocationEntry> withinWalkingDistance(const CharacterId characterId);
  const std::vector<CharacterEntry> closeByCharacters(const CharacterId characterId);
  const std::vector<StructureEntry> closeByStructures(const CharacterId characterId);
  const std::vector<BuildingEntry> closeByBuildings(const CharacterId characterId);
  const std::vector<ExteriorEntry> closeByExteriors(const CharacterId characterId);

  std::optional<ItemId> consumableTypeIn(const ResourceId resourceId, const ConsumableType type);
  ResourceType type(const ResourceId resourceId);

  const std::shared_ptr<entity::Character> &character(const CharacterId characterId);
  const std::shared_ptr<entity::Item> &item(const ItemId itemId);
  const std::shared_ptr<entity::Location> &location(const LocationId locationId);

private:
  std::shared_ptr<World> world;
};

} // namespace model
