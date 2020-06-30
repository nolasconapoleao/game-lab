//
// Created by nolasco on 07/06/20.
//

#include "World.h"

std::vector<entity::Item> World::items;
std::vector<entity::Character> World::characters;
std::vector<entity::Structure> World::structures;
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
  characters.emplace_back(character);
}

entity::Character &World::character(const CharacterId id) {
  return characters.at(id);
}

void World::addItem(entity::Item item) {
  items.emplace_back(item);
}

entity::Item &World::item(const ItemId id) {
  return items.at(id);
}

void World::addStructure(entity::Structure structure) {
  structures.emplace_back(structure);
}

entity::Structure &World::structure(const StructureId id) {
  return structures.at(id);
}

void World::addLocation(LocationId locationId, entity::Location location) {
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

std::vector<std::shared_ptr<entity::Item>> World::itemsOfCharacter(CharacterId characterId) {
  std::vector<std::shared_ptr<entity::Item>> result;
  auto saveItem = [characterId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::CHARACTER) && (item.getOwnership().resourceId == characterId)) {
      result.emplace_back(std::make_shared<entity::Item>(item));
    };
  };
  std::for_each(items.begin(), items.end(), saveItem);
  return result;
}

std::vector<std::shared_ptr<entity::Item>> World::itemsInLocation(CharacterId locationId) {
  std::vector<std::shared_ptr<entity::Item>> result;
  auto saveItem = [locationId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::LOCATION) && (item.getOwnership().resourceId == locationId)) {
      result.emplace_back(std::make_shared<entity::Item>(item));
    };
  };
  std::for_each(items.begin(), items.end(), saveItem);
  return result;
}

std::vector<std::shared_ptr<entity::Character>> World::charactersInLocation(LocationId locationId) {
  std::vector<std::shared_ptr<entity::Character>> result;
  auto saveCharacter = [locationId, &result](entity::Character character) {
    if (character.getLocation() == locationId) {
      result.emplace_back(std::make_shared<entity::Character>(character));
    };
  };
  std::for_each(characters.begin(), characters.end(), saveCharacter);
  return result;
}

std::vector<std::shared_ptr<entity::Structure>> World::structuresInLocation(LocationId locationId) {
  std::vector<std::shared_ptr<entity::Structure>> result;
  auto saveStructure = [locationId, &result](entity::Structure structure) {
    if (structure.getLocation() == locationId) {
      result.emplace_back(std::make_shared<entity::Structure>(structure));
    };
  };
  std::for_each(structures.begin(), structures.end(), saveStructure);
  return result;
}

std::vector<std::shared_ptr<entity::Location>> World::adjcentLocations(LocationId locationId) {
  auto neighbours = worldMap.neighbours(locationId);
  std::vector<std::shared_ptr<entity::Location>> result;

  for (const auto locationId : neighbours) {
    result.emplace_back(std::make_shared<entity::Location>(worldMap.location(locationId)));
  }

  return result;
}

std::vector<LocationId> World::activeLocations() {
  std::vector<LocationId> activeLocationIds;
  auto saveActiveLocation = [&activeLocationIds](entity::Character character) {
    if (character.getGhost() == GhostInTheShell::Player) {
      activeLocationIds.emplace_back(character.getLocation());
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
