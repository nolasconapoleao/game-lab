//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "datatypes/entity-aux/BuildingType.h"
#include "interface/entity/Location.h"

namespace entity {
class Building : public Location {
public:
  Building(const std::string &name, BuildingType type, const Size &size, Quantity floors);
  BuildingType type;
  Number health;
  Number floors;
};
} // namespace entity
