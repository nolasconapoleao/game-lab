//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "datatypes/entity-aux/BuildingType.h"
#include "interface/entity/Location.h"

namespace entity {

/// @brief Building entity.
class Building : public Location {

public:
  /**
   * @brief Constructor.
   * @param name of building.
   * @param type of building.
   * @param size of building.
   * @param floors number of floors for building.
   */
  Building(const std::string &name, BuildingType type, const Size &size, Quantity floors);

  /// @brief type of building.
  BuildingType type;
  /// @brief building health.
  Number health;
  /// @brief number of floors.
  Number floors;
};

} // namespace entity
