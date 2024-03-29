//
// Created by nolasco on 21/07/20.
//

#include <magic_enum/include/magic_enum.hpp>

#include "Factory.h"
#include "model/World.h"
#include "random/Random.h"

namespace model {

StructureId Factory::createStructure(StructureType type) {
  if (type == StructureType::UNDEFINED) {
    type = StructureType{Random::rand(0, static_cast<Quantity>(StructureType::UNDEFINED) - 1)};
  }

  Size size = structureSize(type);
  entity::Structure creation{Random::fromVec(mWorld->teamNames) + "'s " + magic_enum::enum_name(type).data(), type,
                             size};

  mWorld->structures.emplace(++entityCounter, creation);
  return entityCounter;
}

Size Factory::structureSize(const StructureType type) {
  Size size{};
  switch (type) {
    case StructureType::MAILBOX:
      size.width = 2;
      size.height = 2;
      break;
    case StructureType::PHONEBOOTH:
      size.width = 3;
      size.height = 2;
      break;
    case StructureType::UNDEFINED:
      throw std::invalid_argument("Invalid structure action");
  }
  return size;
}

} // namespace model
