//
// Created by nolasco on 16/06/20.
//

#include "EntityFactory.h"

#include "common/GameTypes.h"

EntityFactory::EntityFactory() {
  // Exterior
  exteriorPool.emplace_back(LocationPrototype::TOWN);

  // Interior
  interiorPool.emplace_back(LocationPrototype::ARENA);

  // Connector
  connectorPool.emplace_back(LocationPrototype::CAVE);
}

void EntityFactory::generateCharacter() {
  auto creation = characterFactory.generateCharacter();
  addCharacter(creation);
}

void EntityFactory::createCharacter(const Occupation type) {
  auto creation = characterFactory.createCharacter(type);
  addCharacter(creation);
}

void EntityFactory::createPlayer(const LocationId locationId) {
  auto creation = characterFactory.generateCharacter();
  // TODO: [nn] change to random creation
  creation.setGhost(GhostInTheShell::Player);
  creation.setLocation(0);
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

void EntityFactory::fillLocation(LocationId locationId) {
  // TODO: Implement random generation of entities based on room type
  // FIXME: Amount of entities should be a function of the location size
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

void EntityFactory::createWorld() {
  // TODO: Random creation of rooms
  generateLocation(LocationCategory::Exterior);
  createPlayer(0);

  fillLocation(0);
  generateLocation(LocationCategory::Interior);
  generateLocation(LocationCategory::Interior);
  fillLocation(3);
  generateLocation(LocationCategory::Connector);
  fillLocation(4);
  world.linkLocations(0, 1);
  world.linkLocations(0, 2);
  world.linkLocations(0, 3);
  generateLocation(LocationCategory::Exterior);
  world.linkLocations(3, 4);
  generateLocation(LocationCategory::Interior);
  world.linkLocations(4, 5);
  fillLocation(5);
}

void EntityFactory::resetWorld() {
  world.items.clear();
  world.characters.clear();
  world.structures.clear();
  world.characterQueue.clear();
  // TODO: Delete all rooms
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
