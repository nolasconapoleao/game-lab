//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "CharacterFactory.h"
#include "ItemFactory.h"
#include "StructureFactory.h"
#include "controller/factory/include/LocationPrototype.h"
#include "model/World.h"

class World;

class EntityFactory {
public:
  EntityFactory();
  void generateCharacter();
  void createCharacter(const Occupation type);
  void createPlayer(const LocationId locationId);
  void generateItem(const UseType type);
  void createItem(const ItemPrototype type);
  void generateStructure();
  void createStructure(const StructurePrototype type);
  void generateLocation(const LocationCategory type);
  void createLocation(const LocationPrototype type);
  void fillLocation(LocationId locationId);
  void createWorld();
  void resetWorld();

private:
  void addCharacter(entity::Character character);
  void addItem(entity::Item item);
  void addStructure(entity::Structure structure);
  void addLocation(entity::Location location);

  CharacterFactory characterFactory;
  ItemFactory itemFactory;
  StructureFactory structureFactory;

  std::vector<LocationPrototype> interiorPool;
  std::vector<LocationPrototype> exteriorPool;
  std::vector<LocationPrototype> connectorPool;

  World world;
};
