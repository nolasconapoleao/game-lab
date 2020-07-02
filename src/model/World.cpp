//
// Created by nolasco on 07/06/20.
//

#include "World.h"

std::map<ItemId, entity::Item> World::items;
std::map<CharacterId, entity::Character> World::characters;
std::map<StructureId, entity::Structure> World::structures;
std::vector<CharacterId> World::characterQueue;
WorldMap World::worldMap;
CharacterId World::activeCharacter = 0;
LocationId World::activeLocation = 0;
Number World::queuePosition = 0;

void World::changeFocusedCharacter() {
  queuePosition++;
  if (queuePosition >= characterQueue.size()) {
    queuePosition = 0;
    updateCharacterQueue();
  }
  activeCharacter = characterQueue.at(queuePosition);
  activeLocation = character(activeLocation).getLocation();
}

void World::addCharacter(entity::Character character) {
  if (characters.rbegin() != characters.rend()) {
    characters.emplace(characters.rbegin()->first + 1, character);
  } else {
    characters.emplace(0, character);
  }
}

entity::Character &World::character(const CharacterId id) {
  return characters.at(id);
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

entity::Structure &World::structure(const StructureId id) {
  return structures.at(id);
}

void World::addLocation(entity::Location location) {
  LocationId locationId{static_cast<LocationId>(numberOfLocations())};
  worldMap.addLocation(locationId, location);
}

void World::linkLocations(const LocationId begin, const LocationId end) {
  // TODO: distance is not used
  worldMap.linkLocations(begin, end, 1);
}

size_t World::numberOfLocations() {
  return worldMap.numberOfLocations();
}

entity::Location World::location(const LocationId id) {
  return worldMap.location(id);
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

std::vector<LocationId> World::adjcentLocations(LocationId locationId) {
  return worldMap.neighbours(locationId);
}

std::vector<LocationId> World::activeLocations() {
  std::vector<LocationId> activeLocationIds;
  auto saveActiveLocation = [&activeLocationIds](CharacterEntry entry) {
    if (entry.second.getGhost() == GhostInTheShell::Player) {
      activeLocationIds.emplace_back(entry.second.getLocation());
    };
  };
  std::for_each(characters.begin(), characters.end(), saveActiveLocation);

  std::vector<LocationId> result;
  auto saveAllLocations = [&result](LocationId locationId) { result.emplace_back(locationId); };
  for (const auto activeLocation : activeLocationIds) {
    const auto aux = worldMap.neighbours(activeLocation);
    result.emplace_back();
    std::for_each(aux.begin(), aux.end(), saveAllLocations);
  }

  return result;
}
void World::updateCharacterQueue() {
  // TODO: Don't add dead people to the queue
  characterQueue.clear();
  std::vector<LocationId> locations = activeLocations();

  LocationId characterLocation;
  bool existsInLocation;
  const auto findInLocations = [&characterLocation](LocationId locationId) { return locationId == characterLocation; };
  for (int i = 0; i < characters.size(); i++) {
    characterLocation = characters.at(i).getLocation();
    existsInLocation = (std::find_if(locations.begin(), locations.end(), findInLocations) != locations.end());
    if (existsInLocation) {
      characterQueue.emplace_back(i);
    }
  }
}
