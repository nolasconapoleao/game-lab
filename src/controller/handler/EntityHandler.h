//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "CombatHandler.h"
#include "ItemHandler.h"
#include "TravelHandler.h"
#include "view/Printer.h"

class EntityHandler {
public:
  void updateViewVariables();
  void battle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId);
  void characterGoesTo(const CharacterId &characterId, const LocationId locationId);
  void dropAllItems(const CharacterId characterId, const LocationId locationId);

private:
  ItemHandler itemHandler;
  CombatHandler combatHandler;
  TravelHandler travelHandler;
  World world;
  view::Printer mPrinter;
};
