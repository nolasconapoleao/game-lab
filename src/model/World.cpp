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
