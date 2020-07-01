//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"

#include "common/GameTypes.h"

Factory::Factory() {
  // Exterior
  exteriorPool.emplace_back(LocationPrototype::TOWN);

  // Interior
  interiorPool.emplace_back(LocationPrototype::ARENA);

  // Connector
  connectorPool.emplace_back(LocationPrototype::CAVE);

  occupationPool.emplace_back(Occupation::BLACKSMITH);
  occupationPool.emplace_back(Occupation::BEGGAR);

  // Single Use
  singleUsePool.emplace_back(ItemPrototype::POTION);

  // Equip
  equipPool.emplace_back(ItemPrototype::SWORD);
  equipPool.emplace_back(ItemPrototype::SHIELD);

  structurePool.emplace_back(StructurePrototype::MAILBOX);
}

void Factory::fillLocation(LocationId locationId) {
  // TODO: Implement random generation of entities based on room type
  // FIXME: Amount of entities should be a function of the location size
  generateCharacter();
  world.characters.back().setLocation(locationId);

  generateItem(UseType::singleUse);
  ItemOwnership itemOwnership = {locationId, OwnerType::LOCATION};
  world.items.back().setOwnership(itemOwnership);

  generateStructure();
  world.structures.back().setLocation(locationId);
}

void Factory::createWorld() {
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

void Factory::resetWorld() {
  world.items.clear();
  world.characters.clear();
  world.structures.clear();
  world.characterQueue.clear();
  // TODO: Delete all rooms
}
