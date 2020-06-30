//
// Created by nolasco on 16/06/20.
//

#include "EntityFactory.h"
#include "utils/random/Random.h"

void EntityFactory::addLocation(entity::Location location) {
  // TODO: handle connections to cities
  // TODO: locationId should be calculated based on how many locations already exist
  LocationId locationId{static_cast<LocationId>(world.numberOfLocations())};
  world.addLocation(locationId, location);
}

void EntityFactory::generateLocation(const LocationCategory type) {
  // TODO: [nn] Change access to random element of vector
  std::vector<LocationPrototype>::iterator locationType;

  switch (type) {
    case LocationCategory::Interior:
      locationType = interiorPool.begin();
      std::advance(locationType, Random::fromTo(0, interiorPool.size() - 1));
      break;
    case LocationCategory::Connector:
      locationType = connectorPool.begin();
      std::advance(locationType, Random::fromTo(0, connectorPool.size() - 1));
      break;
    case LocationCategory::Exterior:
      locationType = exteriorPool.begin();
      std::advance(locationType, Random::fromTo(0, exteriorPool.size() - 1));
      break;
  }

  createLocation(*locationType);
}

void EntityFactory::createLocation(LocationPrototype type) {
  // TODO: replace by random generation based on item type
  entity::Location creation;

  switch (type) {
    case LocationPrototype::TOWN:
      creation = entity::Location("Field", LocationCategory::Exterior, Size{50, 20}, 0);
    case LocationPrototype::ARENA:
      creation = entity::Location("Arena", LocationCategory::Interior, Size{10, 10}, 0);
    case LocationPrototype::CAVE:
      creation = entity::Location("Cave", LocationCategory::Connector, Size{30, 5}, 0);
  }

  addLocation(creation);
}
