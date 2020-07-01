//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "controller/factory/include/StructurePrototype.h"
#include "utils/random/Random.h"

void Factory::generateStructure() {
  // TODO: [nn] Change access to random element of vector
  auto type = structurePool.begin();
  std::advance(type, Random::fromTo(0, structurePool.size() - 1));
  createStructure(*type);
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
