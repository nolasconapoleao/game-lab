//
// Created by nolasco on 16/06/20.
//

#include <cmath>

#include "Controller.h"
#include "model/handler/include/gamemath.h"
#include "utils/random/Random.h"

constexpr Number MAXLEVEL = 100;

void handleAttack(entity::Character &attacker, entity::Character &attacked);
void updateExperience(entity::Character &character, Quantity addedXp);
void updateStats(entity::Character &character, Quantity increase);

void Controller::battle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId) {
  auto &attacker = World::character(attackerId);
  auto &attacked = World::character(attackedId);

  handleAttack(attacker, attacked);
  if (attacked.getStats().hp == 0) {
    dropAllItems(attackedId, battleGroundId);
    updateExperience(attacker, gamemath::accumulatedXp(attacked.getStats().lvl, attacked.getStats().xp));
    transferMoney(attackedId, attackerId, attacked.getStats().cash);
  }
}

void handleAttack(entity::Character &attacker, entity::Character &attacked) {
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

  view::Printer::addToRoundReport(Verbose::INFO, hitReport);
  const auto damage_remainder = gamemath::difference(damage, attacked.getTempStats().hp);

  auto updatedBase = attacked.getBaseStats();
  auto updatedTemp = attacked.getTempStats();
  updatedTemp.hp = gamemath::clamp_sub(updatedTemp.hp, damage, 0);
  updatedBase.hp = gamemath::clamp_sub(updatedBase.hp, damage_remainder, 0);

  attacked.setTempStats(updatedTemp);
  attacked.setBaseStats(updatedBase);
}

void updateExperience(entity::Character &character, Quantity addedXp) {
  if (character.isMaxLevelReached()) {
    return;
  }

  auto baseStats = character.getBaseStats();
  Number currentTotal = gamemath::accumulatedXp(baseStats.lvl, baseStats.xp);
  Number finalTotal = currentTotal + addedXp;
  Quantity finalLvl = std::floor((std::sqrt(8 * finalTotal + 1) - 1) / 2);
  Number truncatedFinalTotal = gamemath::accumulatedXp(finalLvl, 0);
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

  updateStats(character, lvlIncrease);
}

void updateStats(entity::Character &character, Quantity increase) {
  // TODO: Add random evolution points
  auto updatedBaseStats = character.getBaseStats();
  updatedBaseStats.mhp += increase;
  updatedBaseStats.hp += increase;

  switch (character.getPassport().occupation) {
    case Occupation::BEGGAR:
      updatedBaseStats.cst += increase;
      break;
    case Occupation::BLACKSMITH:
      updatedBaseStats.def += increase;
      break;
  }
  character.setBaseStats(updatedBaseStats);
}