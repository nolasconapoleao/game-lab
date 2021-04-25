//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Location.h"

namespace entity {

/// @brief Exterior location.
class Exterior : public Location {
public:
  /**
   * @brief Constructor.
   * @param name of exterior.
   * @param size of exterior location.
   */
  Exterior(const std::string &name, const Size &size);
};

} // namespace entity
