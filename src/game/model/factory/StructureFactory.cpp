//
// Created by nolasco on 21/07/20.
//

#include <magic_enum/include/magic_enum.hpp>

#include "Factory.h"
#include "libs/random/Random.h"
#include "model/World.h"

namespace model {

StructureId Factory::createStructure(StructurePrototype type) {
  if (type == StructurePrototype::UNDEFINED) {
    type = StructurePrototype{Random::rand(0, static_cast<Quantity>(StructurePrototype::UNDEFINED) - 1)};
  }

  Size size = structureSize(type);
  entity::Structure creation{magic_enum::enum_name(type).data(), size};

  world->structures.emplace(entityCounter++, creation);
  return entityCounter;
}

Size Factory::structureSize(const StructurePrototype type) {
  Size size;
  switch (type) {
    case StructurePrototype::MAILBOX:
      size.width = 2;
      size.height = 2;
      break;
    case StructurePrototype::PHONEBOOTH:
      size.width = 3;
      size.height = 2;
      break;
  }
  return size;
}

} // namespace model
