//
// Created by nolasco on 07/06/20.
//

#include "World.h"

std::vector<entity::Item> World::items;
std::vector<entity::Character> World::characters;
UndirectedGraph<LocationId, LocationId, Distance> World::worldMap;
CharacterId World::activeCharacter = 0;
LocationId World::activeLocation = 0;

void World::changeFocusedCharacter() {
  const auto numOfCharacters = characters.size();
  activeCharacter++;
  activeCharacter %= numOfCharacters;
}

void World::addCharacter(entity::Character character) {
  characters.emplace_back(character);
}

entity::Character World::character(CharacterId id) {
  return characters.at(id);
}
