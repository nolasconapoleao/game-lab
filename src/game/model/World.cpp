//
// Created by nolasco on 07/06/20.
//

#include "World.h"

CharacterId World::activeCharacter;
std::priority_queue<std::pair<int, CharacterId>> World::characterQueue;
std::map<ResourceId, entity::Character> World::characters;
std::map<ResourceId, entity::Consumable> World::consumables;
std::map<ResourceId, entity::Equipable> World::equipables;
std::map<ResourceId, entity::Exterior> World::exteriors;
std::map<ResourceId, entity::Interior> World::interiors;
std::map<ResourceId, entity::Structure> World::structures;
std::map<ResourceId, entity::Team> World::teams;
std::set<std::pair<LocationId, LocationId>> World::neighbourhoods;
std::set<std::pair<ResourceId, ItemId>> World::possessions;
std::set<std::pair<TeamId, CharacterId>> World::memberships;

void World::loadNextCharacter() {
  if (characterQueue.size() == 0) {
    updateCharacterQueue();
  }
  activeCharacter = characterQueue.top().second;
  characterQueue.pop();
}

void World::addCharacter(entity::Character character) {
  if (characters.rbegin() != characters.rend()) {
    characters.emplace(characters.rbegin()->first + 1, character);
  } else {
    characters.emplace(0, character);
  }
}

void World::addItem(entity::Item item) {
  if (items.rbegin() != items.rend()) {
    items.emplace(items.rbegin()->first + 1, item);
  } else {
    items.emplace(0, item);
  }
}

entity::Item &World::item(const ItemId id) {
  return items.at(id);
}

void World::addStructure(entity::Structure structure) {
  if (structures.rbegin() != structures.rend()) {
    structures.emplace(structures.rbegin()->first + 1, structure);
  } else {
    structures.emplace(0, structure);
  }
}

std::vector<ItemId> World::itemsOfCharacter(CharacterId characterId) {
  std::vector<ItemId> result;
  auto saveItem = [characterId, &result](const ItemEntry &entry) {
    if ((entry.second.getOwnership().ownerType == OwnerType::CHARACTER)
        && (entry.second.getOwnership().resourceId == characterId)) {
      result.emplace_back(entry.first);
    };
  };
  std::for_each(items.begin(), items.end(), saveItem);
  return result;
}

std::vector<ItemId> World::itemsInLocation(CharacterId locationId) {
  std::vector<ItemId> result;
  auto saveItem = [locationId, &result](const ItemEntry &entry) {
    if ((entry.second.getOwnership().ownerType == OwnerType::LOCATION)
        && (entry.second.getOwnership().resourceId == locationId)) {
      result.emplace_back(entry.first);
    };
  };
  std::for_each(items.begin(), items.end(), saveItem);
  return result;
}

std::vector<CharacterId> World::charactersInLocation(LocationId locationId) {
  std::vector<CharacterId> result;
  auto saveCharacter = [locationId, &result](const CharacterEntry &entry) {
    if (entry.second.getLocation() == locationId) {
      result.emplace_back(entry.first);
    };
  };
  std::for_each(characters.begin(), characters.end(), saveCharacter);
  return result;
}

std::vector<StructureId> World::structuresInLocation(LocationId locationId) {
  std::vector<StructureId> result;
  auto saveStructure = [locationId, &result](const StructureEntry &entry) {
    if (entry.second.getLocation() == locationId) {
      result.emplace_back(entry.first);
    };
  };
  std::for_each(structures.begin(), structures.end(), saveStructure);
  return result;
}

std::unordered_set<LocationId> World::adjcentLocations(LocationId locationId) {
  return worldMap.neighbours(locationId);
}

std::set<LocationId> World::activeLocations() {
  std::set<LocationId> locationWithPlayer;
  auto saveActiveLocation = [&locationWithPlayer](CharacterEntry entry) {
    if (entry.second.getGhost() == Ghost::Player) {
      locationWithPlayer.insert(entry.second.getLocation());
    };
  };
  std::for_each(characters.begin(), characters.end(), saveActiveLocation);

  std::set<LocationId> result;
  auto saveAllLocations = [&result](LocationId locationId) { result.insert(locationId); };
  for (const auto activeLocation : locationWithPlayer) {
    const auto aux = worldMap.neighbours(activeLocation);
    std::for_each(aux.begin(), aux.end(), saveAllLocations);
    result.insert(activeLocation);
  }

  return result;
}

void World::updateCharacterQueue() {
  auto locationSet = activeLocations();

  const auto saveToQueue = [&locationSet](const CharacterEntry &entry) {
    // TODO: Don't add dead people or paralysed to the queue
    if (locationSet.contains(entry.second.getLocation())) {
      characterQueue.push({entry.second.getStats().spd, entry.first});
    }
  };
  std::for_each(characters.begin(), characters.end(), saveToQueue);
}
