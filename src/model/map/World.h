//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Location.h"
#include "factory/EntityFactory.h"
#include "model/entity/Character.h"
#include "model/entity/Item.h"
#include "utils/graph/UndirectedGraph.h"

class World {
public:
  static CharacterId activeCharacter;
  static LocationId activeLocation;
  static void changeFocusedCharacter();
  void addCharacter(entity::Character character);
  static entity::Character character(const CharacterId id);

private:
  static std::vector<entity::Item> items;
  static std::vector<entity::Character> characters;
  static UndirectedGraph<LocationId, LocationId, Distance> worldMap;

  friend class EntityFactory;
  friend class CombatHandler;
  friend class ItemHandler;
  friend class TravelHandler;
};
