//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "utils/random/Random.h"

void Factory::generateLocation(const LocationCategory type) {
  LocationPrototype typeId;

  switch (type) {
    case LocationCategory::Interior:
      typeId = Random::fromVec(interiorPool);
      break;
    case LocationCategory::Connector:
      typeId = Random::fromVec(connectorPool);
      break;
    case LocationCategory::Exterior:
      typeId = Random::fromVec(exteriorPool);
      break;
  }

  createLocation(typeId);
}

void Factory::createLocation(const LocationPrototype type) {
  // TODO: replace by random generation based on item type

  entity::Location creation;
  switch (type) {
    case LocationPrototype::TOWN:
      creation = entity::Location("Field", LocationCategory::Exterior, Size{50, 20}, 0);
      break;
    case LocationPrototype::ARENA:
      creation = entity::Location("Arena", LocationCategory::Interior, Size{10, 10}, 0);
      break;
    case LocationPrototype::CAVE:
      creation = entity::Location("Cave", LocationCategory::Connector, Size{30, 5}, 0);
      break;
  }

  world.addLocation(creation);
}
