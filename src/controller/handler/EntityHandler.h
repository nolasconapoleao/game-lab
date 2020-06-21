//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "CombatHandler.h"
#include "ItemHandler.h"
#include "TravelHandler.h"

class EntityHandler {
public:
  void attack(entity::Character &attacker, entity::Character &attacked);

private:
  std::vector<entity::Item> itemsOfCharacter(CharacterId characterId);
  std::vector<entity::Item> itemsInLocation(LocationId locationId);
  std::vector<entity::Character> charactersInLocation(const LocationId locationId);
  std::vector<entity::Structure> structuresInLocation(const LocationId locationId);
  std::vector<entity::Location> adjcentLocations(const LocationId locationId);

  ItemHandler itemHandler;
  CombatHandler combatHandler;
  TravelHandler travelHandler;
  World world;
};
