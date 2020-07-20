//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "interface/entity/Entity.h"

namespace entity {

class Structure : public Entity {
public:
  Structure(const std::string &name, const Size &size);

  Size size;
};

} // namespace entity
