//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Location.h"

namespace entity {
class Interior : public Location {
public:
  Interior(const std::string &name, const Size &size, Number floors);

  Number floors;
};
} // namespace entity
