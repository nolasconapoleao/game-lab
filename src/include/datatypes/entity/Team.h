//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Entity.h"

namespace entity {

/// @brief Team entity.
class Team : public Entity {
public:
  /**
   * @brief Constructor.
   * @param name of team.
   */
  explicit Team(const std::string &name);
};

} // namespace entity
