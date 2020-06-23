//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "CharacterFactory.h"
#include "ItemFactory.h"
#include "LocationFactory.h"
#include "StructureFactory.h"
#include "model/World.h"

class World;

class EntityFactory {
public:
  void generateCharacter();
  void createCharacter(const Occupation type);
  void createPlayer();
  void generateItem(const UseType type);
  void createItem(const ItemPrototype type);
  void generateStructure();
  void createStructure(const StructurePrototype type);
  void generateLocation(const LocationCategory type);
  void createLocation(const LocationPrototype type);
  void fillLocation(LocationId locationId);

private:
  void addCharacter(entity::Character character);
  void addItem(entity::Item item);
  void addStructure(entity::Structure structure);
  void addLocation(entity::Location location);

  CharacterFactory characterFactory;
  ItemFactory itemFactory;
  LocationFactory locationFactory;
  StructureFactory structureFactory;
  World world;
};
