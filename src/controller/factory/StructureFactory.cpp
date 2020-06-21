//
// Created by nolasco on 16/06/20.
//

#include "StructureFactory.h"

#include "controller/factory/include/StructurePrototype.h"
#include "utils/random/Random.h"

StructureFactory::StructureFactory() {
  structurePool.emplace_back(StructurePrototype::MAILBOX);
}

entity::Structure StructureFactory::generateStructure() {
  // TODO: [nn] Change access to random element of vector
  auto type = structurePool.begin();
  std::advance(type, Random::fromTo(0, structurePool.size() - 1));
  return createStructure(*type);
}

entity::Structure StructureFactory::createStructure(StructurePrototype type) {
  // TODO: replace by random generation based on item type

  switch (type) {
    case StructurePrototype::MAILBOX:
      return entity::Structure("Mailbox", Size{1, 2});
  }
}
