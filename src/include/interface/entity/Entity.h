//
// Created by nolasco on 19/07/20.
//

#pragma once

#include <string>
#include <utility>

namespace entity {

/// @brief Game entity.
class Entity {
public:
  /**
   * @brief Game entity name.
   * @param name of game entity.
   */
  explicit Entity(std::string name) : name(std::move(name)) {
  }

  /// @brief Name of game entity.
  std::string name;
};

} // namespace entity
