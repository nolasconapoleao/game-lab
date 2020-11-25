//
// Created by nolasco on 21/07/20.
//

#include "Lookup.h"

#include <utility>

#include "model/World.h"

namespace model {

Lookup::Lookup(std::shared_ptr<World> world) : mWorld(std::move(world)) {
}

std::vector<DbEntry<entity::Item>> Lookup::itemsIn(const ResourceId resourceId) {
  std::vector<DbEntry<entity::Item>> result;
  const auto &consumables = consumablesIn(resourceId);
  for (const auto &entry : consumables) {
    result.emplace_back(DbEntry<entity::Item>{
        entry.id, std::make_shared<entity::Consumable>(mWorld->consumables.find(entry.id)->second)});
  };

  const auto &equippables = equippablesIn(resourceId);
  for (const auto &entry : equippables) {
    result.emplace_back(DbEntry<entity::Item>{
        entry.id, std::make_shared<entity::Equippable>(mWorld->equippables.find(entry.id)->second)});
  };
  return result;
}

std::vector<DbEntry<entity::Consumable>> Lookup::consumablesIn(const ResourceId resourceId) {
  std::vector<DbEntry<entity::Consumable>> result;
  for (const auto &[itemId, ownerId] : mWorld->locatedIn) {
    if (ownerId == resourceId && CONSUMABLE == type(itemId)) {
      result.emplace_back(DbEntry<entity::Consumable>{
          itemId, std::make_shared<entity::Consumable>(mWorld->consumables.find(itemId)->second)});
    }
  }
  return result;
}

std::vector<DbEntry<entity::Equippable>> Lookup::equippablesIn(const ResourceId resourceId) {
  std::vector<DbEntry<entity::Equippable>> result;
  for (const auto &[itemId, ownerId] : mWorld->locatedIn) {
    if (ownerId == resourceId && EQUIPPABLE == type(itemId)) {
      result.emplace_back(DbEntry<entity::Equippable>{
          itemId, std::make_shared<entity::Equippable>(mWorld->equippables.find(itemId)->second)});
    }
  }
  return result;
}

std::vector<DbEntry<entity::Character>> Lookup::charactersIn(const LocationId locationId) {
  std::vector<DbEntry<entity::Character>> result;
  for (const auto &[resourceId, locatedInId] : mWorld->locatedIn) {
    if (locatedInId == locationId && CHARACTER == type(resourceId)) {
      result.emplace_back(DbEntry<entity::Character>{
          resourceId, std::make_shared<entity::Character>(mWorld->characters.find(resourceId)->second)});
    }
  };
  return result;
}

std::vector<DbEntry<entity::Structure>> Lookup::structuresIn(const LocationId locationId) {
  std::vector<DbEntry<entity::Structure>> result;
  for (const auto &[resourceId, locatedInId] : mWorld->locatedIn) {
    if (locatedInId == locationId && STRUCTURE == type(resourceId)) {
      result.emplace_back(DbEntry<entity::Structure>{
          resourceId, std::make_shared<entity::Structure>(mWorld->structures.find(resourceId)->second)});
    }
  };
  return result;
}

std::vector<DbEntry<entity::Exterior>> Lookup::neighbourExteriors(LocationId locationId) {
  std::vector<DbEntry<entity::Exterior>> result;
  for (const auto &[startId, endId] : mWorld->neighbours) {
    if (endId == locationId && EXTERIOR == type(startId)) {
      result.emplace_back(DbEntry<entity::Exterior>{
          startId, std::make_shared<entity::Exterior>(mWorld->exteriors.find(startId)->second)});
    }
  };
  return result;
}

std::vector<DbEntry<entity::Building>> Lookup::neighbourBuildings(LocationId locationId) {
  std::vector<DbEntry<entity::Building>> result;
  for (const auto &[startId, endId] : mWorld->neighbours) {
    if (endId == locationId && BUILDING == type(startId)) {
      result.emplace_back(DbEntry<entity::Building>{
          startId, std::make_shared<entity::Building>(mWorld->buildings.find(startId)->second)});
    }
  };
  return result;
}

std::vector<DbEntry<entity::Location>> Lookup::neighbourLocations(const LocationId locationId) {
  std::vector<DbEntry<entity::Location>> result;
  const auto &buildings = neighbourBuildings(locationId);
  for (const auto &entry : buildings) {
    result.emplace_back(DbEntry<entity::Location>{
        entry.id, std::make_shared<entity::Location>(mWorld->buildings.find(entry.id)->second)});
  };

  const auto &exteriors = neighbourExteriors(locationId);
  for (const auto &entry : exteriors) {
    result.emplace_back(DbEntry<entity::Location>{
        entry.id, std::make_shared<entity::Location>(mWorld->exteriors.find(entry.id)->second)});
  };
  return result;
}

std::vector<DbEntry<entity::Location>> Lookup::neighboursEndingIn(const LocationId locationId) {
  std::vector<DbEntry<entity::Location>> result;
  for (const auto &[startId, endId] : mWorld->neighbours) {
    if (endId == locationId) {
      if (EXTERIOR == type(locationId)) {
        result.emplace_back(DbEntry<entity::Location>{
            startId, std::make_shared<entity::Exterior>(mWorld->exteriors.find(endId)->second)});
      } else if (BUILDING == type(locationId)) {
        result.emplace_back(DbEntry<entity::Location>{
            startId, std::make_shared<entity::Building>(mWorld->buildings.find(endId)->second)});
      }
    }
  };
  return result;
}

[[maybe_unused]] std::vector<DbEntry<entity::Location>> Lookup::closeByLocations(const CharacterId characterId) {
  const auto locationId = mWorld->locatedIn[characterId];
  return neighbourLocations(locationId);
}

std::vector<DbEntry<entity::Character>> Lookup::closeByCharacters(CharacterId characterId) {
  const auto locationId = mWorld->locatedIn[characterId];
  auto characters = charactersIn(locationId);
  std::erase_if(characters, [characterId](const auto &character) { return character.id == characterId; });
  return characters;
}

std::vector<DbEntry<entity::Structure>> Lookup::closeByStructures(CharacterId characterId) {
  const auto locationId = mWorld->locatedIn[characterId];
  return structuresIn(locationId);
}

std::vector<DbEntry<entity::Building>> Lookup::closeByBuildings(CharacterId characterId) {
  const auto locationId = mWorld->locatedIn[characterId];
  return neighbourBuildings(locationId);
}

std::vector<DbEntry<entity::Exterior>> Lookup::closeByExteriors(CharacterId characterId) {
  const auto locationId = mWorld->locatedIn[characterId];
  return neighbourExteriors(locationId);
}

DbEntry<entity::Location> Lookup::whereIs(CharacterId characterId) {
  const auto locationId = mWorld->locatedIn[characterId];
  return DbEntry<entity::Location>{locationId, location(locationId)};
}

std::vector<DbEntry<entity::Character>> Lookup::playableCharacters() {
  std::vector<DbEntry<entity::Character>> result;
  for (const auto &[id, entity] : mWorld->characters) {
    if (Ghost::PLAYER == entity.info.ghost) {
      result.emplace_back(DbEntry<entity::Character>{id, std::make_shared<entity::Character>(entity)});
    }
  };
  return result;
}

std::optional<ItemId> Lookup::consumableTypeIn(ResourceId resourceId, ConsumableType type) {
  for (const auto &consumable : mWorld->consumables) {
    if (consumable.second.type == type && mWorld->locatedIn[consumable.first] == resourceId) {
      return consumable.first;
    }
  }
  return {};
}

ResourceType Lookup::type(const ResourceId resourceId) {
  if (mWorld->equippables.contains(resourceId)) {
    return ResourceType::EQUIPPABLE;
  }

  if (mWorld->consumables.contains(resourceId)) {
    return ResourceType::CONSUMABLE;
  }

  if (mWorld->exteriors.contains(resourceId)) {
    return ResourceType::EXTERIOR;
  }

  if (mWorld->buildings.contains(resourceId)) {
    return ResourceType::BUILDING;
  }

  if (mWorld->characters.contains(resourceId)) {
    return ResourceType::CHARACTER;
  }

  if (mWorld->structures.contains(resourceId)) {
    return ResourceType::STRUCTURE;
  }

  if (mWorld->teams.contains(resourceId)) {
    return ResourceType::TEAM;
  }
  throw std::invalid_argument("Invalid entity action");
}

std::shared_ptr<entity::Character> Lookup::character(CharacterId characterId) {
  return std::make_shared<entity::Character>(mWorld->characters.find(characterId)->second);
}

std::shared_ptr<entity::Item> Lookup::item(const ItemId itemId) {
  if (mWorld->consumables.contains(itemId)) {
    return std::make_shared<entity::Consumable>(mWorld->consumables.find(itemId)->second);
  }

  if (mWorld->equippables.contains(itemId)) {
    return std::make_shared<entity::Equippable>(mWorld->equippables.find(itemId)->second);
  }

  throw std::invalid_argument("Invalid item accessed");
}

std::shared_ptr<entity::Location> Lookup::location(const LocationId locationId) {
  if (mWorld->exteriors.contains(locationId)) {
    return std::make_shared<entity::Exterior>(mWorld->exteriors.find(locationId)->second);
  }

  if (mWorld->buildings.contains(locationId)) {
    return std::make_shared<entity::Building>(mWorld->buildings.find(locationId)->second);
  }

  throw std::invalid_argument("Invalid location accessed");
}

bool Lookup::characterExists(const CharacterId characterId) {
  return mWorld->characters.contains(characterId);
}

} // namespace model
