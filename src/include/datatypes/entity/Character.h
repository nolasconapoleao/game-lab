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

/// @brief Character entity.
class Character : public Entity {

public:
  /**
   * @brief Constructor.
   * @param name of character.
   * @param baseStats for character.
   * @param info for character.
   */
  Character(const std::string &name, const Stats &baseStats, const Info &info);

  /**
   * @brief Sum of temporary and base character stats.
   * @return sum of temporary and base character stats.
   */
  Stats stats() const;

  /// @brief Character base stats.
  Stats base;
  /// @brief Character temporary stats.
  ItemEffect temp;
  /// @brief Character information.
  Info info;
  /// @brief List of active status effects.
  std::unordered_set<StatusEffect> effects;
};

} // namespace entity
