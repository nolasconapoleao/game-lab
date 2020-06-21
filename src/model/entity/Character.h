//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "model/entity/include/GhostInTheShell.h"
#include "model/entity/include/ItemEffect.h"
#include "model/entity/include/Passport.h"
#include "model/entity/include/Stats.h"

namespace entity {

class Character {
public:
  Character(const std::string &name, const Stats &baseStats, GhostInTheShell ghost);

  void addXp(Quantity addedXp);
  bool levelMaxedOut();

  const ItemEffect &getBaseStats() const;
  const Passport &getPass() const;
  const std::string &getName() const;
  GhostInTheShell getGhost() const;

private:
  static Number totalXp(Quantity lvl, Quantity xp);
  void evolve(Quantity levelIncrease);

  std::string name;
  Stats baseStats;
  ItemEffect tempStats;
  GhostInTheShell ghost;
  Passport passport;
  bool maxLevelReached;
  LocationId location;
};
} // namespace entity
