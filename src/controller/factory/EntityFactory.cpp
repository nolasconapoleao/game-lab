//
// Created by nolasco on 16/06/20.
//

#include "EntityFactory.h"

#include "common/GameTypes.h"

void EntityFactory::generateCharacter() {
  auto creation = characterFactory.generateCharacter();
  addCharacter(creation);
}

void EntityFactory::createCharacter(const Occupation type) {
  auto creation = characterFactory.createCharacter(type);
  addCharacter(creation);
}

void EntityFactory::createPlayer() {
  auto creation = characterFactory.generateCharacter();
  // TODO: [nn] change to random creation
  creation.setGhost(GhostInTheShell::Player);
  addCharacter(creation);
}

void EntityFactory::generateItem(const UseType type) {
  auto creation = itemFactory.generateItem(type);
  addItem(creation);
}

void EntityFactory::createItem(ItemPrototype type) {
  // TODO: items should have a location or character owner
  auto creation = itemFactory.createItem(type);
  addItem(creation);
}

void EntityFactory::generateLocation(LocationCategory type) {
  auto creation = locationFactory.generateLocation(type);
  addLocation(creation);
}

void EntityFactory::createLocation(LocationPrototype type) {
  auto creation = locationFactory.createLocation(type);
  addLocation(creation);
}

void EntityFactory::addCharacter(entity::Character character) {
  world.addCharacter(character);
}

void EntityFactory::addItem(entity::Item item) {
  world.addItem(item);
}

void EntityFactory::addLocation(entity::Location location) {
  // TODO: handle connections to cities
  // TODO: locationId should be calculated based on how many locations already exist
  LocationId locationId{1};
  world.addLocation(locationId, location);
}
