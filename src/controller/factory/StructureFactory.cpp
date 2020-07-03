//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "controller/factory/include/StructurePrototype.h"
#include "utils/random/Random.h"

void Factory::generateStructure() {
  const auto typeId = Random::fromVec(structurePool);
  createStructure(typeId);
}

void Factory::createStructure(StructurePrototype type) {
  // TODO: replace by random generation based on item type
  entity::Structure creation;
  switch (type) {
    case StructurePrototype::MAILBOX:
      creation = entity::Structure("Mailbox", Size{1, 2});
      break;
  }

  world.addStructure(creation);
}
