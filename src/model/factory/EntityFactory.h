//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "CharacterFactory.h"
#include "ItemFactory.h"
#include "LocationFactory.h"
#include "model/World.h"

class World;

class EntityFactory {
public:
  void generateCharacter();
  void createCharacter(const Occupation type);
  void generateItem(const UseType type);
  void createItem(const ItemPrototype type);
  void generateLocation(const LocationCategory type);
  void createLocation(const LocationPrototype type);

private:
  void addCharacter(entity::Character character);
  void addItem(entity::Item item);
  void addLocation(entity::Location location);

  CharacterFactory characterFactory;
  ItemFactory itemFactory;
  LocationFactory locationFactory;
  World world;
};
