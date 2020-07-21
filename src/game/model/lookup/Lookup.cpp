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
  const auto findItem = [this, &result, resourceId](const auto &entry) {
    if (entry.second == resourceId) {
      if (world->consumables.contains(resourceId)) {
        result.emplace_back(
            ItemEntry{entry.first, std::make_shared<entity::Consumable>(world->consumables.find(entry.second).second)});
      } else if (world->equipables.contains(resourceId)) {
        result.emplace_back(
            ItemEntry{entry.first, std::make_shared<entity::Equipable>(world->equipables.find(entry.second).second)});
      }
    }
  };
  std::for_each(world->possessions.begin(), world->possessions.end(), findItem);
  return result;
}

const std::vector<CharacterEntry> &Lookup::charactersIn(LocationId locationId) {
  std::vector<CharacterEntry> result;
  const auto findCharacter = [this, &result, locationId](const auto &entry) {
    if (entry.second == locationId) {
      result.emplace_back(CharacterEntry{
          entry.first, std::make_shared<entity::Character>(world->characters.find(entry.second).second)});
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findCharacter);
  return result;
}

const std::vector<StructureEntry> &Lookup::structuresIn(LocationId locationId) {
  std::vector<StructureEntry> result;
  const auto findStructure = [this, &result, locationId](const auto &entry) {
    if (entry.second == locationId) {
      result.emplace_back(StructureEntry{
          entry.first, std::make_shared<entity::Structure>(world->structures.find(entry.second).second)});
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findStructure);
  return result;
}

const std::vector<LocationEntry> &Lookup::neighbourLocations(LocationId locationId) {
  std::vector<LocationEntry> result = neighbourStartingIn(locationId);
  std::vector<LocationEntry> endsIn = neighboursEndingIn(locationId);
  result.insert(std::end(result), std::begin(endsIn), std::end(endsIn));
  return result;
}

const std::vector<LocationEntry> &Lookup::neighboursEndingIn(LocationId locationId) {
  std::vector<LocationEntry> result;
  const auto findNeighbour = [this, &result, locationId](const auto &entry) {
    if (entry.second == locationId) {
      if (world->exteriors.contains(locationId)) {
        result.emplace_back(
            LocationEntry{entry.first, std::make_shared<entity::Exterior>(world->exteriors.find(entry.second).second)});
      } else if (world->buildings.contains(locationId)) {
        result.emplace_back(
            LocationEntry{entry.first, std::make_shared<entity::Building>(world->buildings.find(entry.second).second)});
      }
    }
  };
  std::for_each(world->neighbours.begin(), world->neighbours.end(), findNeighbour);
  return result;
}

const std::vector<LocationEntry> &Lookup::neighbourStartingIn(LocationId locationId) {
  std::vector<LocationEntry> result;
  const auto findNeighbour = [this, &result, locationId](const auto &entry) {
    if (entry.first == locationId) {
      if (world->exteriors.contains(locationId)) {
        result.emplace_back(
            LocationEntry{entry.second, std::make_shared<entity::Exterior>(world->exteriors.find(entry.first).second)});
      } else if (world->buildings.contains(locationId)) {
        result.emplace_back(
            LocationEntry{entry.second, std::make_shared<entity::Building>(world->buildings.find(entry.first).second)});
      }
    }
  };
  std::for_each(world->neighbours.begin(), world->neighbours.end(), findNeighbour);
  return result;
}

} // namespace model
