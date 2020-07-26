//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <memory>
#include <vector>

#include "datatypes/lookup/ResourceEntry.h"

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

  const std::vector<LocationEntry> closeByLocations(const CharacterId characterId);
  const std::vector<CharacterEntry> closeByCharacters(const CharacterId characterId);
  const std::vector<StructureEntry> closeByStructures(const CharacterId characterId);
  const std::vector<BuildingEntry> closeByBuildings(const CharacterId characterId);
  const std::vector<ExteriorEntry> closeByExteriors(const CharacterId characterId);
  LocationEntry whereIs(CharacterId characterId);

  const std::vector<CharacterEntry> playableCharacters();

  std::optional<ItemId> consumableTypeIn(const ResourceId resourceId, const ConsumableType type);
  ResourceType type(const ResourceId resourceId);

  std::shared_ptr<entity::Character> character(CharacterId characterId);
  std::shared_ptr<entity::Item> item(const ItemId itemId);
  std::shared_ptr<entity::Location> location(const LocationId locationId);

  bool characterExists(const CharacterId characterId);

private:
  std::shared_ptr<World> world;
};

} // namespace model
