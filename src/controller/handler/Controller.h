//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "common/GameTypes.h"
#include "model/World.h"
#include "model/entity/include/ItemOwnerType.h"
#include "view/Printer.h"

class Controller {
public:
  void updateViewVariables();
  void battle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId);
  void characterGoesTo(const CharacterId &characterId, const LocationId locationId);
  void dropAllItems(const CharacterId characterId, const LocationId locationId);
  void changeItemOwner(ItemId item, const OwnerType &type, const ResourceId newOwner);
  void strategize(const CharacterId characterId);

private:
  void handleAttack(entity::Character &attacker, entity::Character &attacked);

  void addXp(entity::Character &character, Quantity addedXp);
  // Auxiliary methods
  static Number totalXp(Quantity lvl, Quantity xp);
  void evolve(Quantity levelIncrease);
  void updateStats(Quantity increase);

  view::Printer mPrinter;
  World world;
};
