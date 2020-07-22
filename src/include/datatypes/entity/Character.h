//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <unordered_set>

#include "datatypes/entity-aux/Info.h"
#include "datatypes/entity-aux/Stats.h"
#include "datatypes/entity-aux/StatusEffect.h"
#include "interface/entity/Entity.h"

namespace entity {

class Character : public Entity {
public:
  Character(const std::string &name, const Stats &baseStats, const Info &info);
  Stats stats() const;

  Stats base;
  ItemEffect temp;
  Info info;
  std::unordered_set<StatusEffect> effects;
};
} // namespace entity
