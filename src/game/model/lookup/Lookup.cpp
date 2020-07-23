//
// Created by nolasco on 21/07/20.
//

#include "Lookup.h"

#include "model/World.h"

namespace model {

Lookup::Lookup(const std::shared_ptr<World> &world) : world(std::move(world)) {
}

const std::vector<ItemEntry> &Lookup::itemsIn(const ResourceId resourceId) {
  std::vector<ItemEntry> result;
  const auto addConsumable = [this, &result](const auto &entry) {
    result.emplace_back(
        ItemEntry{entry.id, std::make_shared<entity::Consumable>(world->consumables.find(entry.id)->second)});
  };
  const auto addEquippable = [this, &result](const auto &entry) {
    result.emplace_back(
        ItemEntry{entry.id, std::make_shared<entity::Equippable>(world->equippables.find(entry.id)->second)});
  };
  const auto &consumables = consumablesIn(resourceId);
  const auto &equippables = equippablesIn(resourceId);
  std::for_each(consumables.begin(), consumables.end(), addConsumable);
  std::for_each(equippables.begin(), equippables.end(), addEquippable);
  return std::move(result);
}

const std::vector<ConsumableEntry> &Lookup::consumablesIn(const ResourceId resourceId) {
  std::vector<ConsumableEntry> result;
  const auto findItem = [this, &result, resourceId](const auto &entry) {
    if (entry.second == resourceId) {
      if (world->consumables.contains(resourceId)) {
        result.emplace_back(ConsumableEntry{
            entry.first, std::make_shared<entity::Consumable>(world->consumables.find(entry.second)->second)});
      }
    }
  };
  std::for_each(world->possessions.begin(), world->possessions.end(), findItem);
  return std::move(result);
}

const std::vector<EquippableEntry> &Lookup::equippablesIn(const ResourceId resourceId) {
  std::vector<EquippableEntry> result;
  const auto findItem = [this, &result, resourceId](const auto &entry) {
    if (entry.second == resourceId) {
      if (world->equippables.contains(resourceId)) {
        result.emplace_back(EquippableEntry{
            entry.first, std::make_shared<entity::Equippable>(world->equippables.find(entry.second)->second)});
      }
    }
  };
  std::for_each(world->possessions.begin(), world->possessions.end(), findItem);
  return std::move(result);
}

const std::vector<CharacterEntry> &Lookup::charactersIn(const LocationId locationId) {
  std::vector<CharacterEntry> result;
  const auto findCharacter = [this, &result, locationId](const auto &entry) {
    if (entry.second == locationId) {
      result.emplace_back(CharacterEntry{
          entry.first, std::make_shared<entity::Character>(world->characters.find(entry.second)->second)});
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findCharacter);
  return std::move(result);
}

const std::vector<StructureEntry> &Lookup::structuresIn(const LocationId locationId) {
  std::vector<StructureEntry> result;
  const auto findStructure = [this, &result, locationId](const auto &entry) {
    if (entry.second == locationId) {
      result.emplace_back(StructureEntry{
          entry.first, std::make_shared<entity::Structure>(world->structures.find(entry.second)->second)});
    }
  };
  std::for_each(world->locatedIn.begin(), world->locatedIn.end(), findStructure);
  return std::move(result);
}

const std::vector<ExteriorEntry> &Lookup::neighbourExteriors(LocationId locationId) {
  std::vector<ExteriorEntry> result;
  const auto findNeighbour = [this, &result, locationId](const auto &entry) {
    if (entry.first == locationId) {
      if (world->exteriors.contains(locationId)) {
        result.emplace_back(ExteriorEntry{
            entry.second, std::make_shared<entity::Exterior>(world->exteriors.find(entry.first)->second)});
      }
    }
  };
  std::for_each(world->neighbours.begin(), world->neighbours.end(), findNeighbour);
  return std::move(result);
}

const std::vector<BuildingEntry> &Lookup::neighbourBuildings(LocationId locationId) {
  std::vector<BuildingEntry> result;
  const auto findNeighbour = [this, &result, locationId](const auto &entry) {
    if (entry.first == locationId) {
      if (world->buildings.contains(locationId)) {
        result.emplace_back(BuildingEntry{
            entry.second, std::make_shared<entity::Building>(world->buildings.find(entry.first)->second)});
      }
    }
  };
  std::for_each(world->neighbours.begin(), world->neighbours.end(), findNeighbour);
  return std::move(result);
}

const std::vector<LocationEntry> &Lookup::neighbourLocations(const LocationId locationId) {
  std::vector<LocationEntry> result = neighbourStartingIn(locationId);
  std::vector<LocationEntry> endsIn = neighboursEndingIn(locationId);
  result.insert(std::end(result), std::begin(endsIn), std::end(endsIn));
  return std::move(result);
}

const std::vector<LocationEntry> &Lookup::neighboursEndingIn(const LocationId locationId) {
  std::vector<LocationEntry> result;
  const auto findNeighbour = [this, &result, locationId](const auto &entry) {
    if (entry.second == locationId) {
      if (world->exteriors.contains(locationId)) {
        result.emplace_back(LocationEntry{
            entry.first, std::make_shared<entity::Exterior>(world->exteriors.find(entry.second)->second)});
      } else if (world->buildings.contains(locationId)) {
        result.emplace_back(LocationEntry{
            entry.first, std::make_shared<entity::Building>(world->buildings.find(entry.second)->second)});
      }
    }
  };
  std::for_each(world->neighbours.begin(), world->neighbours.end(), findNeighbour);
  return std::move(result);
}

const std::vector<LocationEntry> &Lookup::neighbourStartingIn(const LocationId locationId) {
  std::vector<LocationEntry> result;
  const auto addExterior = [this, &result](const auto &entry) {
    result.emplace_back(
        LocationEntry{entry.id, std::make_shared<entity::Exterior>(world->exteriors.find(entry.id)->second)});
  };
  const auto addBuilding = [this, &result](const auto &entry) {
    result.emplace_back(
        LocationEntry{entry.id, std::make_shared<entity::Building>(world->buildings.find(entry.id)->second)});
  };
  const auto &exteriors = neighbourExteriors(locationId);
  const auto &buildings = neighbourExteriors(locationId);
  std::for_each(exteriors.begin(), exteriors.end(), addExterior);
  std::for_each(buildings.begin(), buildings.end(), addBuilding);
  return std::move(result);
}

const std::vector<LocationEntry> &Lookup::withinWalkingDistance(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return neighbourStartingIn(locationId);
}

const std::vector<CharacterEntry> &Lookup::closeByCharacters(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  auto characters = charactersIn(locationId);
  std::erase_if(characters, [characterId](const auto &character) { return character.id == characterId; });
  return characters;
}

const std::vector<StructureEntry> &Lookup::closeByStructures(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return structuresIn(locationId);
}

const std::vector<BuildingEntry> &Lookup::closeByBuildings(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return neighbourBuildings(locationId);
}

std::optional<ItemId> Lookup::consumableTypeIn(ResourceId resourceId, ConsumableType type) {
  const auto findConsumable = [this, resourceId, type](const auto &entry) {
    if (entry.second.type == type && world->possessions[entry.first] == resourceId) {
      return entry.first;
    }
  };
  std::for_each(world->consumables.begin(), world->consumables.end(), findConsumable);
  return {};
}

bool Lookup::isEquippable(ItemId itemId) {
  return world->equippables.contains(itemId);
}

bool Lookup::isConsumable(ItemId itemId) {
  return world->consumables.contains(itemId);
}

bool Lookup::isExterior(LocationId locationId) {
  return world->exteriors.contains(locationId);
}

bool Lookup::isBuilding(LocationId locationId) {
  return world->buildings.contains(locationId);
}

const std::shared_ptr<entity::Character> &Lookup::character(CharacterId characterId) {
  return std::make_shared<entity::Character>(world->characters.find(characterId)->second);
}

const std::shared_ptr<entity::Item> &Lookup::item(ItemId itemId) {
  if (world->consumables.contains(itemId)) {
    return std::make_shared<entity::Consumable>(world->consumables.find(itemId)->second);
  } else if (world->equippables.contains(itemId)) {
    return std::make_shared<entity::Equippable>(world->equippables.find(itemId)->second);
  }
}

const std::shared_ptr<entity::Location> &Lookup::location(LocationId locationId) {
  if (world->exteriors.contains(locationId)) {
    return std::make_shared<entity::Exterior>(world->exteriors.find(locationId)->second);
  } else if (world->buildings.contains(locationId)) {
    return std::make_shared<entity::Building>(world->buildings.find(locationId)->second);
  }
}

} // namespace model
