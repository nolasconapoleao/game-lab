//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "datatypes/entity-aux/StructureType.h"
#include "interface/entity/Entity.h"

namespace entity {

/// @brief Structure entity.
class Structure : public Entity {
public:
  /**
   * @brief Constructor.
   * @param name of structure.
   * @param type of structure.
   * @param size of structure.
   */
  Structure(const std::string &name, StructureType type, const Size &size);

  /// @brief Structure type.
  StructureType type;
  /// @brief Structure health.
  Number health;
  /// @brief Structure size.
  Size size;
};

} // namespace entity
