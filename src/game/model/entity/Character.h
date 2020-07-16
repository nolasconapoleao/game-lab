//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "game/model/entity/include/GhostInTheShell.h"
#include "game/model/entity/include/ItemEffect.h"
#include "game/model/entity/include/Passport.h"
#include "game/model/entity/include/Stats.h"

namespace entity {

class Character {
public:
  Character() = default;
  Character(const std::string &name, const Stats &baseStats, Passport passport, GhostInTheShell ghost);
  const std::string &getName() const;
  void setName(const std::string &name);
  const Stats &getBaseStats() const;
  void setBaseStats(const Stats &baseStats);
  const ItemEffect &getTempStats() const;
  void setTempStats(const ItemEffect &tempStats);
  const Stats getStats() const;
  GhostInTheShell getGhost() const;
  void setGhost(GhostInTheShell ghost);
  const Passport &getPassport() const;
  void setPassport(const Passport &passport);
  bool isMaxLevelReached() const;
  void setMaxLevelReached(bool maxLevelReached);
  LocationId getLocation() const;
  void setLocation(LocationId location);

private:
  // TODO: Use name Id to lookup instead of string
  std::string name;
  Stats baseStats;
  ItemEffect tempStats;
  GhostInTheShell ghost;
  Passport passport;
  bool maxLevelReached;
  LocationId location;
};
} // namespace entity
