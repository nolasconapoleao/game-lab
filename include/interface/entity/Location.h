//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Entity.h"
#include "datatypes/GameTypes.h"

namespace entity {

/// @brief Location entity.
class Location : public Entity {
public:
  /**
   * @brief Constructor.
   * @param name of location.
   * @param size of location.
   */
  Location(const std::string &name, const Size &size)
      : Entity(name)
      , size(size) {
  }

  /// @brief Location size.
  Size size;
};

} // namespace entity
