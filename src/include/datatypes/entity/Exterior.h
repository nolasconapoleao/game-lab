//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Location.h"

namespace entity {

class Exterior : public Location {
public:
  Exterior(const std::string &name, const Size &size);
};

} // namespace entity
