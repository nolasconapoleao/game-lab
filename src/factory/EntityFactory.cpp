//
// Created by nolasco on 16/06/20.
//

#include "EntityFactory.h"
void EntityFactory::generateCharacter() {
  auto creation = characterFactory.generateCharacter();
  addCharacter(creation);
}

void EntityFactory::createCharacter(CharacterType type) {
  auto creation = characterFactory.createCharacter(type);
  addCharacter(creation);
}

void EntityFactory::addCharacter(entity::Character character) {
  World world;
  world.addCharacter(character);
}
