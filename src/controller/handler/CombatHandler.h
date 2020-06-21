//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <model/entity/Character.h>

// TODO: [nn] Implementation of use cases missing
class CombatHandler {
public:
  void handleAttack(entity::Character &attacker, entity::Character &attacked);

private:
  void addXp(entity::Character &character, Quantity addedXp);

  // Auxiliary methods
  static Number totalXp(Quantity lvl, Quantity xp);
  void evolve(Quantity levelIncrease);
  void updateStats(Quantity increase);
};
