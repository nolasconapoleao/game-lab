//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "datatypes/factory/StructurePrototype.h"
#include "libs/random/Random.h"

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

  World::addStructure(creation);
}
