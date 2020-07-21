//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <unordered_set>

#include "datatypes/entity/Info.h"
#include "datatypes/entity/Stats.h"
#include "datatypes/entity/StatusEffect.h"
#include "interface/entity/Entity.h"

namespace entity {

class Character : public Entity {
public:
  Character(const std::string &name, const Stats &baseStats, const Info &info);

  Stats baseStats;
  ItemEffect tempStats;
  Info info;
  std::unordered_set<StatusEffect> effects;
};
} // namespace entity
