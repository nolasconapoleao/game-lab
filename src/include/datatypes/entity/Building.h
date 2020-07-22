//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Location.h"

namespace entity {
class Building : public Location {
public:
  Building(const std::string &name, const Size &size, Quantity floors);
  Number health;
  Number floors;
};
} // namespace entity
