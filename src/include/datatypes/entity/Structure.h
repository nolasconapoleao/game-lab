//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "datatypes/entity-aux/StructureType.h"
#include "interface/entity/Entity.h"

namespace entity {

class Structure : public Entity {
public:
  Structure(const std::string &name, StructureType type, const Size &size);

  StructureType type;
  Number health;
  Size size;
};

} // namespace entity
