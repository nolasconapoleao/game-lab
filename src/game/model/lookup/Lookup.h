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
  explicit Lookup(std::shared_ptr<World> world);
  std::vector<ItemEntry> itemsIn(ResourceId resourceId);
  std::vector<ConsumableEntry> consumablesIn(ResourceId resourceId);
  std::vector<EquippableEntry> equippablesIn(ResourceId resourceId);
  std::vector<CharacterEntry> charactersIn(LocationId locationId);
  std::vector<StructureEntry> structuresIn(LocationId locationId);
  std::vector<ExteriorEntry> neighbourExteriors(LocationId locationId);
  std::vector<BuildingEntry> neighbourBuildings(LocationId locationId);
  std::vector<LocationEntry> neighbourLocations(LocationId locationId);
  std::vector<LocationEntry> neighboursEndingIn(LocationId locationId);

  [[maybe_unused]] std::vector<LocationEntry> closeByLocations(CharacterId characterId);
  std::vector<CharacterEntry> closeByCharacters(CharacterId characterId);
  std::vector<StructureEntry> closeByStructures(CharacterId characterId);
  std::vector<BuildingEntry> closeByBuildings(CharacterId characterId);
  std::vector<ExteriorEntry> closeByExteriors(CharacterId characterId);
  LocationEntry whereIs(CharacterId characterId);

  std::vector<CharacterEntry> playableCharacters();

  std::optional<ItemId> consumableTypeIn(ResourceId resourceId, ConsumableType type);
  ResourceType type(ResourceId resourceId);

  std::shared_ptr<entity::Character> character(CharacterId characterId);
  std::shared_ptr<entity::Item> item(ItemId itemId);
  std::shared_ptr<entity::Location> location(LocationId locationId);

  bool characterExists(CharacterId characterId);

private:
  std::shared_ptr<World> world;
};

} // namespace model
