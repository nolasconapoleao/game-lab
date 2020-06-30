//
// Created by nolasco on 16/06/20.
//

#include "CombatHandler.h"

#include <cmath>

#include "controller/handler/include/gamemath.h"

constexpr Number MAXLEVEL = 100;

void CombatHandler::handleAttack(entity::Character &attacker, entity::Character &attacked) {
  // TODO: [nn] Include random hit probability
  auto attackerStats = attacker.getStats();
  auto attackedStats = attacked.getStats();

  const auto damage = attackerStats.atk;
  const auto damage_remainder = gamemath::difference(damage, attacked.getTempStats().hp);

  auto updatedBase = attacked.getBaseStats();
  auto updatedTemp = attacked.getTempStats();
  updatedTemp.hp = gamemath::clamp_sub(updatedTemp.hp, damage, 0);
  updatedBase.hp = gamemath::clamp_sub(updatedBase.hp, damage_remainder, 0);

  attacked.setTempStats(updatedTemp);
  attacked.setBaseStats(updatedBase);
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
