//
// Created by nolasco on 21/07/20.
//

#include "Lookup.h"

#include <utility>

#include "model/World.h"

namespace model {

Lookup::Lookup(std::shared_ptr<World> world) : world(std::move(world)) {
}

std::vector<ItemEntry> Lookup::itemsIn(const ResourceId resourceId) {
  std::vector<ItemEntry> result;
  const auto &consumables = consumablesIn(resourceId);
  for (const auto &entry : consumables) {
    result.emplace_back(
        ItemEntry{entry.id, std::make_shared<entity::Consumable>(world->consumables.find(entry.id)->second)});
  };

  const auto &equippables = equippablesIn(resourceId);
  for (const auto &entry : equippables) {
    result.emplace_back(
        ItemEntry{entry.id, std::make_shared<entity::Equippable>(world->equippables.find(entry.id)->second)});
  };
  return result;
}

std::vector<ConsumableEntry> Lookup::consumablesIn(const ResourceId resourceId) {
  std::vector<ConsumableEntry> result;
  for (const auto &[itemId, ownerId] : world->locatedIn) {
    if (ownerId == resourceId && CONSUMABLE == type(itemId)) {
      result.emplace_back(
          ConsumableEntry{itemId, std::make_shared<entity::Consumable>(world->consumables.find(itemId)->second)});
    }
  }
  return result;
}

std::vector<EquippableEntry> Lookup::equippablesIn(const ResourceId resourceId) {
  std::vector<EquippableEntry> result;
  for (const auto &[itemId, ownerId] : world->locatedIn) {
    if (ownerId == resourceId && EQUIPPABLE == type(itemId)) {
      result.emplace_back(
          EquippableEntry{itemId, std::make_shared<entity::Equippable>(world->equippables.find(itemId)->second)});
    }
  }
  return result;
}

std::vector<CharacterEntry> Lookup::charactersIn(const LocationId locationId) {
  std::vector<CharacterEntry> result;
  for (const auto &[resourceId, locatedInId] : world->locatedIn) {
    if (locatedInId == locationId && CHARACTER == type(resourceId)) {
      result.emplace_back(
          CharacterEntry{resourceId, std::make_shared<entity::Character>(world->characters.find(resourceId)->second)});
    }
  };
  return result;
}

std::vector<StructureEntry> Lookup::structuresIn(const LocationId locationId) {
  std::vector<StructureEntry> result;
  for (const auto &[resourceId, locatedInId] : world->locatedIn) {
    if (locatedInId == locationId && STRUCTURE == type(resourceId)) {
      result.emplace_back(
          StructureEntry{resourceId, std::make_shared<entity::Structure>(world->structures.find(resourceId)->second)});
    }
  };
  return result;
}

std::vector<ExteriorEntry> Lookup::neighbourExteriors(LocationId locationId) {
  std::vector<ExteriorEntry> result;
  for (const auto &[startId, endId] : world->neighbours) {
    if (endId == locationId && EXTERIOR == type(startId)) {
      result.emplace_back(
          ExteriorEntry{startId, std::make_shared<entity::Exterior>(world->exteriors.find(startId)->second)});
    }
  };
  return result;
}

std::vector<BuildingEntry> Lookup::neighbourBuildings(LocationId locationId) {
  std::vector<BuildingEntry> result;
  for (const auto &[startId, endId] : world->neighbours) {
    if (endId == locationId && BUILDING == type(startId)) {
      result.emplace_back(
          BuildingEntry{startId, std::make_shared<entity::Building>(world->buildings.find(startId)->second)});
    }
  };
  return result;
}

std::vector<LocationEntry> Lookup::neighbourLocations(const LocationId locationId) {
  std::vector<LocationEntry> result;
  const auto &buildings = neighbourBuildings(locationId);
  for (const auto &entry : buildings) {
    result.emplace_back(
        LocationEntry{entry.id, std::make_shared<entity::Location>(world->buildings.find(entry.id)->second)});
  };

  const auto &exteriors = neighbourExteriors(locationId);
  for (const auto &entry : exteriors) {
    result.emplace_back(
        LocationEntry{entry.id, std::make_shared<entity::Location>(world->exteriors.find(entry.id)->second)});
  };
  return result;
}

std::vector<LocationEntry> Lookup::neighboursEndingIn(const LocationId locationId) {
  std::vector<LocationEntry> result;
  for (const auto &[startId, endId] : world->neighbours) {
    if (endId == locationId) {
      if (EXTERIOR == type(locationId)) {
        result.emplace_back(
            LocationEntry{startId, std::make_shared<entity::Exterior>(world->exteriors.find(endId)->second)});
      } else if (BUILDING == type(locationId)) {
        result.emplace_back(
            LocationEntry{startId, std::make_shared<entity::Building>(world->buildings.find(endId)->second)});
      }
    }
  };
  return result;
}

[[maybe_unused]] std::vector<LocationEntry> Lookup::closeByLocations(const CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return neighbourLocations(locationId);
}

std::vector<CharacterEntry> Lookup::closeByCharacters(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  auto characters = charactersIn(locationId);
  std::erase_if(characters, [characterId](const auto &character) { return character.id == characterId; });
  return characters;
}

std::vector<StructureEntry> Lookup::closeByStructures(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return structuresIn(locationId);
}

std::vector<BuildingEntry> Lookup::closeByBuildings(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return neighbourBuildings(locationId);
}

std::vector<ExteriorEntry> Lookup::closeByExteriors(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return neighbourExteriors(locationId);
}

LocationEntry Lookup::whereIs(CharacterId characterId) {
  const auto locationId = world->locatedIn[characterId];
  return LocationEntry{locationId, location(locationId)};
}

std::vector<CharacterEntry> Lookup::playableCharacters() {
  std::vector<CharacterEntry> result;
  for (const auto &[id, entity] : world->characters) {
    if (Ghost::PLAYER == entity.info.ghost) {
      result.emplace_back(CharacterEntry{id, std::make_shared<entity::Character>(entity)});
    }
  };
  return result;
}

std::optional<ItemId> Lookup::consumableTypeIn(ResourceId resourceId, ConsumableType type) {
  for (const auto &consumable : world->consumables) {
    if (consumable.second.type == type && world->locatedIn[consumable.first] == resourceId) {
      return consumable.first;
    }
  }
  return {};
}

ResourceType Lookup::type(const ResourceId resourceId) {
  if (world->equippables.contains(resourceId)) {
    return ResourceType::EQUIPPABLE;
  }

  if (world->consumables.contains(resourceId)) {
    return ResourceType::CONSUMABLE;
  }

  if (world->exteriors.contains(resourceId)) {
    return ResourceType::EXTERIOR;
  }

  if (world->buildings.contains(resourceId)) {
    return ResourceType::BUILDING;
  }

  if (world->characters.contains(resourceId)) {
    return ResourceType::CHARACTER;
  }

  if (world->structures.contains(resourceId)) {
    return ResourceType::STRUCTURE;
  }

  if (world->teams.contains(resourceId)) {
    return ResourceType::TEAM;
  }
  throw std::invalid_argument("Invalid entity type");
}

std::shared_ptr<entity::Character> Lookup::character(CharacterId characterId) {
  return std::make_shared<entity::Character>(world->characters.find(characterId)->second);
}

std::shared_ptr<entity::Item> Lookup::item(const ItemId itemId) {
  if (world->consumables.contains(itemId)) {
    return std::make_shared<entity::Consumable>(world->consumables.find(itemId)->second);
  }

  if (world->equippables.contains(itemId)) {
    return std::make_shared<entity::Equippable>(world->equippables.find(itemId)->second);
  }

  throw std::invalid_argument("Invalid item accessed");
}

std::shared_ptr<entity::Location> Lookup::location(const LocationId locationId) {
  if (world->exteriors.contains(locationId)) {
    return std::make_shared<entity::Exterior>(world->exteriors.find(locationId)->second);
  }

  if (world->buildings.contains(locationId)) {
    return std::make_shared<entity::Building>(world->buildings.find(locationId)->second);
  }

  throw std::invalid_argument("Invalid location accessed");
}

bool Lookup::characterExists(const CharacterId characterId) {
  return world->characters.contains(characterId);
}

} // namespace model
