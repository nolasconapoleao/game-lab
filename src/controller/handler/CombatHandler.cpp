//
// Created by nolasco on 16/06/20.
//

#include <cmath>

#include "Controller.h"
#include "controller/handler/include/gamemath.h"
#include "utils/random/Random.h"

constexpr Number MAXLEVEL = 100;

void Controller::handleAttack(entity::Character &attacker, entity::Character &attacked) {
  auto attackerStats = attacker.getStats();
  auto attackedStats = attacked.getStats();

  auto hitChange = Random::fromTo(0, attackerStats.atk);
  auto defenseChange = Random::fromTo(0, attackedStats.def);

  auto damage = 0;
  std::string hitReport = attacker.getName() + " attacks " + attacked.getName() + ": ";
  if (hitChange > (2 * defenseChange)) {
    damage = 2 * (hitChange - defenseChange);
    hitReport += "Critical";
  } else if (hitChange > defenseChange) {
    damage = hitChange - defenseChange;
    hitReport += "Hit";
  } else {
    hitReport += "Fail";
  }
  mPrinter.addToRoundReport(Verbose::INFO, hitReport);
  const auto damage_remainder = gamemath::difference(damage, attacked.getTempStats().hp);

  auto updatedBase = attacked.getBaseStats();
  auto updatedTemp = attacked.getTempStats();
  updatedTemp.hp = gamemath::clamp_sub(updatedTemp.hp, damage, 0);
  updatedBase.hp = gamemath::clamp_sub(updatedBase.hp, damage_remainder, 0);

  attacked.setTempStats(updatedTemp);
  attacked.setBaseStats(updatedBase);
}

void Controller::addXp(entity::Character &character, Quantity addedXp) {
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

Number Controller::totalXp(Quantity lvl, Quantity xp) {
  auto result = std::pow(lvl, 2) + xp;
  return result;
}

void Controller::updateStats(Quantity increase) {
  // TODO: unimplemented
}
