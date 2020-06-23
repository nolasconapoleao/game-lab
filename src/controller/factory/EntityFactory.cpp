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

void EntityFactory::generateStructure() {
  auto creation = structureFactory.generateStructure();
  addStructure(creation);
}

void EntityFactory::createStructure(StructurePrototype type) {
  // TODO: structures should have a location or character owner
  auto creation = structureFactory.createStructure(type);
  addStructure(creation);
}

void EntityFactory::generateLocation(LocationCategory type) {
  auto creation = locationFactory.generateLocation(type);
  addLocation(creation);
}

void EntityFactory::createLocation(LocationPrototype type) {
  auto creation = locationFactory.createLocation(type);
  addLocation(creation);
}

void EntityFactory::fillLocation(LocationId locationId) {
  // TODO: Implement random generation of entities based on room type
  auto characterCreation = characterFactory.generateCharacter();
  characterCreation.setLocation(locationId);
  addCharacter(characterCreation);

  auto itemCreation = itemFactory.generateItem(UseType::singleUse);
  ItemOwnership itemOwnership = {locationId, OwnerType::LOCATION};
  itemCreation.setOwnership(itemOwnership);
  addItem(itemCreation);

  auto structureCreation = structureFactory.generateStructure();
  structureCreation.setLocation(locationId);
  addStructure(structureCreation);
}

void EntityFactory::addCharacter(entity::Character character) {
  world.addCharacter(character);
}

void EntityFactory::addItem(entity::Item item) {
  world.addItem(item);
}
void EntityFactory::addStructure(entity::Structure structure) {
  world.addStructure(structure);
}
void EntityFactory::addLocation(entity::Location location) {
  // TODO: handle connections to cities
  // TODO: locationId should be calculated based on how many locations already exist
  LocationId locationId{0};
  world.addLocation(locationId, location);
}
