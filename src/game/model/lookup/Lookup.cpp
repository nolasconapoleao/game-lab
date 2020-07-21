//
// Created by nolasco on 21/07/20.
//

#include "Lookup.h"

#include "model/World.h"

namespace model {

Lookup::Lookup(const std::shared_ptr<World> &world) : world(world) {
}

const std::vector<ItemEntry> &Lookup::itemsIn(ResourceId resourceId) {
  std::vector<ItemEntry> result;
  const auto findItem = [this, &result, resourceId](StructureId id) {
    if (id == resourceId) {
      if (world->consumables.contains(resourceId)) {
        result.emplace_back(ItemEntry{id, std::make_shared<entity::Consumable>(world->consumables.find(id)->second)});
      } else if (world->equipables.contains(resourceId)) {
        result.emplace_back(ItemEntry{id, std::make_shared<entity::Equipable>(world->equipables.find(id)->second)});
      }
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findItem);
  return result;
}

const std::vector<CharacterEntry> &Lookup::charactersIn(LocationId locationId) {
  std::vector<CharacterEntry> result;
  const auto findCharacter = [this, &result, locationId](CharacterId id) {
    if (id == locationId) {
      result.emplace_back(CharacterEntry{id, std::make_shared<entity::Character>(world->characters.find(id)->second)});
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findCharacter);
  return result;
}

const std::vector<StructureEntry> &Lookup::structuresIn(LocationId locationId) {
  std::vector<StructureEntry> result;
  const auto findStructure = [this, &result, locationId](StructureId id) {
    if (id == locationId) {
      result.emplace_back(StructureEntry{id, std::make_shared<entity::Structure>(world->structures.find(id)->second)});
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findStructure);
  return result;
}

const std::vector<LocationEntry> &Lookup::neighbourLocations(LocationId locationId) {
  std::vector<LocationEntry> result;
  const auto findNeighbour = [this, &result, locationId](LocationId id) {
    if (id == locationId) {
      if (world->exteriors.contains(locationId)) {
        result.emplace_back(LocationEntry{id, std::make_shared<entity::Exterior>(world->exteriors.find(id)->second)});
      } else if (world->buildings.contains(locationId)) {
        result.emplace_back(LocationEntry{id, std::make_shared<entity::Building>(world->buildings.find(id)->second)});
      }
    }
  };
  std::for_each(world->neighbours.begin(), world->neighbours.end(), findNeighbour);
  return result;
}

} // namespace model
