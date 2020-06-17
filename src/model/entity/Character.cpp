//
// Created by nolasco on 07/06/20.
//

#include "Character.h"

#include <cmath>

constexpr Number MAXLEVEL = 100;

namespace entity {

Character::Character(const Property &baseStats, GhostInTheShell ghost, const std::string &name)
    : baseStats(baseStats), ghost(ghost), maxLevelReached(false), name(name) {
}

void Character::addXp(Quantity addedXp) {
  Number currentTotal = totalXp(pass.lvl, pass.xp);
  Number finalTotal = currentTotal + addedXp;
  Quantity finalLvl = std::floor((std::sqrt(8 * finalTotal + 1) - 1) / 2);
  Number truncatedFinalTotal = totalXp(finalLvl, 0);
  Quantity finalXp = finalTotal - truncatedFinalTotal;

  // Update level variables
  if (finalLvl >= MAXLEVEL) {
    maxLevelReached = true;
    pass.lvl = MAXLEVEL;
    pass.xp = 0;
  } else {
    pass.lvl = finalLvl;
    pass.xp = finalXp;
  }

  // Evolve character
  Quantity lvlIncrease = finalLvl - pass.lvl;
  evolve(lvlIncrease);
}

Number Character::totalXp(Quantity lvl, Quantity xp) {
  auto result = std::pow(lvl, 2) + xp;
  return result;
}

bool Character::levelMaxedOut() {
  return maxLevelReached;
}

const Property &Character::getBaseStats() const {
  return baseStats;
}

const Wallet &Character::getPass() const {
  return pass;
}

const std::string &Character::getName() const {
  return name;
}

GhostInTheShell Character::getGhost() const {
  return ghost;
}

void Character::evolve(Quantity levelIncrease) {
  // TODO: evolve is a function of the character class
}

// TODO: move this method somewhere apropriate
// Property &operator+(Property &first, Property &second) {
//  Property result{static_cast<Quantity>(first.atk + second.atk), static_cast<Quantity>(first.def + second.def),
//                  static_cast<Quantity>(first.spd + second.spd), static_cast<Quantity>(first.hp + second.hp),
//                  static_cast<Quantity>(first.mhp + second.mhp)};
//}

} // namespace entity
