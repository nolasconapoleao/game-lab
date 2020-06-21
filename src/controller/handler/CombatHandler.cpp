//
// Created by nolasco on 16/06/20.
//

#include "CombatHandler.h"

#include <cmath>

constexpr Number MAXLEVEL = 100;

void CombatHandler::handleAttack(entity::Character &attacker, entity::Character &attacked) {
  // TODO: [nn] Include random hit probability
  // TODO: [nn] Include clamp for hp
  auto attackerStats = attacker.getBaseStats();
  auto attackedStats = attacked.getBaseStats();

  attackedStats.hp -= attackerStats.atk;
  attacked.setBaseStats(attackedStats);
}

void CombatHandler::addXp(entity::Character &character, Quantity addedXp) {
  auto baseStats = character.getBaseStats();
  Number currentTotal = totalXp(baseStats.lvl, baseStats.xp);
  Number finalTotal = currentTotal + addedXp;
  Quantity finalLvl = std::floor((std::sqrt(8 * finalTotal + 1) - 1) / 2);
  Number truncatedFinalTotal = totalXp(finalLvl, 0);
  Quantity finalXp = finalTotal - truncatedFinalTotal;

  // Update level variables
  if (finalLvl >= MAXLEVEL) {
    character.setMaxLevelReached(true);
    baseStats.lvl = MAXLEVEL;
    baseStats.xp = 0;
  } else {
    baseStats.lvl = finalLvl;
    baseStats.xp = finalXp;
  }

  Quantity lvlIncrease = finalLvl - baseStats.lvl;
  character.setBaseStats(baseStats);

  // Evolve character
  updateStats(lvlIncrease);
}

Number CombatHandler::totalXp(Quantity lvl, Quantity xp) {
  auto result = std::pow(lvl, 2) + xp;
  return result;
}

void CombatHandler::updateStats(Quantity increase) {
  // TODO: unimplemented
}
