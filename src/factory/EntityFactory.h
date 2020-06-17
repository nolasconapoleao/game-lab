//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "CharacterFactory.h"
#include "ItemFactory.h"
#include "LocationFactory.h"
#include "model/map/World.h"

class World;

class EntityFactory {
public:
  void generateCharacter();
  void createCharacter(const CharacterType type);

private:
  void addCharacter(entity::Character character);

  CharacterFactory characterFactory;
  ItemFactory itemFactory;
  LocationFactory locationFactory;
};
