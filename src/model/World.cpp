//
// Created by nolasco on 07/06/20.
//

#include "World.h"

std::vector<entity::Item> World::items;
std::vector<entity::Character> World::characters;
std::vector<entity::Structure> World::structures;
WorldMap World::worldMap;
CharacterId World::activeCharacter = 0;
LocationId World::activeLocation = 0;

void World::changeFocusedCharacter() {
  const auto numOfCharacters = characters.size();
  activeCharacter++;
  activeCharacter %= numOfCharacters;
}

void World::changeFocusedLocation() {
  // TODO: implement change of active location
}

void World::addCharacter(entity::Character character) {
  characters.emplace_back(character);
}

entity::Character World::character(CharacterId id) {
  return characters.at(id);
}

void World::addItem(entity::Item item) {
  items.emplace_back(item);
}

entity::Item World::item(ItemId id) {
  return items.at(id);
}

void World::addStructure(entity::Structure structure) {
  structures.emplace_back(structure);
}

entity::Structure World::structure(StructureId id) {
  return structures.at(id);
}

void World::addLocation(LocationId locationId, entity::Location location) {
  worldMap.addLocation(locationId, location);
}

entity::Location World::location(LocationId id) {
  return worldMap.location(id);
}

std::vector<entity::Item> World::itemsOfCharacter(CharacterId characterId) {
  std::vector<entity::Item> result;
  auto saveItem = [characterId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::CHARACTER) && (item.getOwnership().resourceId == characterId)) {
      result.emplace_back(item);
    };
  };
  std::for_each(items.begin(), items.end(), saveItem);
  return result;
}

std::vector<entity::Item> World::itemsInLocation(CharacterId locationId) {
  std::vector<entity::Item> result;
  auto saveItem = [locationId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::LOCATION) && (item.getOwnership().resourceId == locationId)) {
      result.emplace_back(item);
    };
  };
  std::for_each(items.begin(), items.end(), saveItem);
  return result;
}

std::vector<entity::Character> World::charactersInLocation(LocationId locationId) {
  std::vector<entity::Character> result;
  auto saveCharacter = [locationId, &result](entity::Character character) {
    if (character.getLocation() == locationId) {
      result.emplace_back(character);
    };
  };
  std::for_each(characters.begin(), characters.end(), saveCharacter);
  return result;
}

std::vector<entity::Structure> World::structuresInLocation(LocationId locationId) {
  std::vector<entity::Structure> result;
  auto saveStructure = [locationId, &result](entity::Structure structure) {
    if (structure.getLocation() == locationId) {
      result.emplace_back(structure);
    };
  };
  std::for_each(structures.begin(), structures.end(), saveStructure);
  return result;
}

std::vector<entity::Location> World::adjcentLocations(LocationId locationId) {
  auto neighbours = worldMap.neighbours(locationId);
  std::vector<entity::Location> result;

  for (const auto locationId : neighbours) {
    result.emplace_back(worldMap.location(locationId));
  }

  return result;
}

std::vector<entity::Location> World::activeLocations() {
  std::vector<LocationId> activeLocationIds;
  auto saveActiveLocation = [&activeLocationIds](entity::Character character) {
    if (character.getGhost() == GhostInTheShell::Player) {
      activeLocationIds.emplace_back(character.getLocation());
    };
  };
  std::for_each(characters.begin(), characters.end(), saveActiveLocation);

  std::vector<LocationId> unpackedLocationIds;
  auto saveAllLocations
      = [&unpackedLocationIds](LocationId locationId) { unpackedLocationIds.emplace_back(locationId); };
  for (const auto activeLocation : activeLocationIds) {
    const auto aux = worldMap.neighbours(activeLocation);
    unpackedLocationIds.emplace_back();
    std::for_each(aux.begin(), aux.end(), saveAllLocations);
  }

  std::vector<entity::Location> result;
  for (const auto locationId : unpackedLocationIds) {
    result.emplace_back(worldMap.location(locationId));
  }

  return result;
}
