//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "GhostInTheShell.h"
#include "Property.h"
#include "Wallet.h"

namespace entity {

class Character {
public:
  Character(const Property &baseStats, GhostInTheShell ghost, const std::string &name);

  void think();
  void addXp(Quantity addedXp);
  bool levelMaxedOut();

  const Property &getBaseStats() const;
  const Wallet &getPass() const;
  const std::string &getName() const;
  GhostInTheShell getGhost() const;

private:
  static Number totalXp(Quantity lvl, Quantity xp);
  void evolve(Quantity levelIncrease);

  Property baseStats;
  Property tempStats;
  GhostInTheShell ghost;
  Wallet pass;
  bool maxLevelReached;
  std::string name;
  LocationId location;
  // TODO: add strategy
};
} // namespace entity
