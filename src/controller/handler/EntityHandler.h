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
  void attack(entity::Character &attacker, entity::Character &attacked);

private:
  ItemHandler itemHandler;
  CombatHandler combatHandler;
  TravelHandler travelHandler;
  World world;
  view::Printer mPrinter;
};
