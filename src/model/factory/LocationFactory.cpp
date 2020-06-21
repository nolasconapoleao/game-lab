//
// Created by nolasco on 16/06/20.
//

#include "LocationFactory.h"

#include <utils/random/Random.h>

#include "model/factory/include/LocationPrototype.h"

LocationFactory::LocationFactory() {
  // Exterior
  exteriorPool.emplace_back(LocationPrototype::TOWN);

  // Interior
  interiorPool.emplace_back(LocationPrototype::ARENA);

  // Connector
  connectorPool.emplace_back(LocationPrototype::CAVE);
}

entity::Location LocationFactory::generateLocation(const LocationCategory type) {
  // TODO: [nn] Change access to random element of vector
  std::vector<LocationPrototype>::iterator locationType;

  switch (type) {
    case LocationCategory::Interior:
      locationType = interiorPool.begin();
      std::advance(locationType, Random::fromTo(0,interiorPool.size()-1));
      break;
    case LocationCategory::Connector:
      locationType = connectorPool.begin();
      std::advance(locationType, Random::fromTo(0,connectorPool.size()-1));
      break;
    case LocationCategory::Exterior:
      locationType = exteriorPool.begin();
      std::advance(locationType, Random::fromTo(0,exteriorPool.size()-1));
      break;
  }
  return createLocation(*locationType);
}

entity::Location LocationFactory::createLocation(LocationPrototype type) {
  // TODO: replace by random generation based on item type

  switch (type) {
    case LocationPrototype::TOWN:
      return entity::Location("Field", LocationCategory::Exterior, Size{50, 20}, 0);
    case LocationPrototype::ARENA:
      return entity::Location("Arena", LocationCategory::Interior, Size{10, 10}, 0);
    case LocationPrototype::CAVE:
      return entity::Location("Cave", LocationCategory::Connector, Size{30, 5}, 0);
  }
}