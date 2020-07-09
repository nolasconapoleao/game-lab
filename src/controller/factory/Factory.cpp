//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"

#include "common/GameTypes.h"

Factory::Factory() {
  // LOCATION
  // Exterior
  exteriorPool.emplace_back(LocationPrototype::TOWN);
  // Interior
  interiorPool.emplace_back(LocationPrototype::ARENA);
  // Connector
  connectorPool.emplace_back(LocationPrototype::CAVE);

  // CHARACTER
  occupationPool.emplace_back(Occupation::BLACKSMITH);
  occupationPool.emplace_back(Occupation::BEGGAR);

  // ITEM
  // Single Use
  singleUsePool.emplace_back(ItemPrototype::POTION);
  // Equip
  equipPool.emplace_back(ItemPrototype::SWORD);
  equipPool.emplace_back(ItemPrototype::SHIELD);

  // STRUCTURE
  structurePool.emplace_back(StructurePrototype::MAILBOX);
}

void Factory::fillLocation(LocationId locationId) {
  // TODO: Implement random generation of entities based on room type
  // FIXME: Amount of entities should be a function of the location size
  generateCharacter();
  World::characters.rbegin()->second.setLocation(locationId);

  generateItem(UseType::singleUse);
  ItemOwnership itemOwnership = {locationId, OwnerType::LOCATION};
  World::items.rbegin()->second.setOwnership(itemOwnership);

  generateStructure();
  World::structures.rbegin()->second.setLocation(locationId);
}

void Factory::fillInventory(CharacterId characterId) {
  // TODO: Implement random generation of entities based on character type
  generateItem(UseType::singleUse);
  ItemOwnership itemOwnership = {characterId, OwnerType::CHARACTER};
  World::items.rbegin()->second.setOwnership(itemOwnership);
  generateItem(UseType::equip);
  World::items.rbegin()->second.setOwnership(itemOwnership);
}

void Factory::createWorld() {
  // TODO: Random creation of rooms
  generateLocation(LocationCategory::Exterior);
  createPlayer(0);
  World::characters.rbegin()->second.setName("Player");
  fillInventory(World::characters.rbegin()->first);

  fillLocation(0);
  generateLocation(LocationCategory::Interior);
  generateLocation(LocationCategory::Interior);
  fillLocation(3);
  generateLocation(LocationCategory::Connector);
  fillLocation(4);
  World::linkLocations(0, 1);
  World::linkLocations(0, 2);
  World::linkLocations(0, 3);
  generateLocation(LocationCategory::Exterior);
  World::linkLocations(3, 4);
  generateLocation(LocationCategory::Interior);
  World::linkLocations(4, 5);
  fillLocation(5);
}
