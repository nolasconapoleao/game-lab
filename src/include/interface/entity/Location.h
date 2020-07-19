//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "Entity.h"
#include "datatypes/GameTypes.h"

namespace entity {

class Location : public Entity {
public:
  Location(const std::string &name, const Size &size) : Entity(name), size(size) {
  }

private:
  Size size;
};

} // namespace entity
