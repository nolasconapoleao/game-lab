//
// Created by nolasco on 07/06/20.
//

#include "Character.h"

#include "math/gamemath.h"

namespace entity {

Character::Character(const std::string &name, const Stats &baseStats, Passport passport, GhostInTheShell ghost)
    : baseStats(baseStats), ghost(ghost), maxLevelReached(false), name(name) {
}

const std::string &Character::getName() const {
  return name;
}

void Character::setName(const std::string &name) {
  Character::name = name;
}

const Stats &Character::getBaseStats() const {
  return baseStats;
}

void Character::setBaseStats(const Stats &baseStats) {
  Character::baseStats = baseStats;
}

const ItemEffect &Character::getTempStats() const {
  return tempStats;
}

void Character::setTempStats(const ItemEffect &tempStats) {
  Character::tempStats = tempStats;
}

const Stats Character::getStats() const {
  const auto stats = baseStats + tempStats;
  return stats;
}

GhostInTheShell Character::getGhost() const {
  return ghost;
}

void Character::setGhost(GhostInTheShell ghost) {
  Character::ghost = ghost;
}

const Passport &Character::getPassport() const {
  return passport;
}

void Character::setPassport(const Passport &passport) {
  Character::passport = passport;
}

bool Character::isMaxLevelReached() const {
  return maxLevelReached;
}

void Character::setMaxLevelReached(bool maxLevelReached) {
  Character::maxLevelReached = maxLevelReached;
}

LocationId Character::getLocation() const {
  return location;
}

void Character::setLocation(LocationId location) {
  Character::location = location;
}

} // namespace entity
