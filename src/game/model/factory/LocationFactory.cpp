//
// Created by nolasco on 21/07/20.
//

#include <magic_enum/include/magic_enum.hpp>

#include "Factory.h"
#include "libs/random/Random.h"
#include "model/World.h"

namespace model {
LocationId Factory::createConnector(ConnectorPrototype type) {
  if (type == ConnectorPrototype::UNDEFINED) {
    type = ConnectorPrototype{Random::rand(0, static_cast<Quantity>(ConnectorPrototype::UNDEFINED))};
  }

  Size size = connectorSize(type);
  entity::Exterior creation{Random::fromVec(world->locationNames) + " " + magic_enum::enum_name(type).data(), size};

  world->exteriors.emplace(entityCounter++, creation);
  return entityCounter;
}

LocationId Factory::createBuilding(BuildingPrototype type) {
  if (type == BuildingPrototype::UNDEFINED) {
    type = BuildingPrototype{Random::rand(0, static_cast<Quantity>(BuildingPrototype::UNDEFINED))};
  }

  auto [size, floors] = buildingSpecs(type);
  entity::Building creation{Random::fromVec(world->locationNames) + " " + magic_enum::enum_name(type).data(), size,
                            floors};

  world->buildings.emplace(entityCounter++, creation);
  return entityCounter;
}

LocationId Factory::createLocation(ExteriorPrototype type) {
  if (type == ExteriorPrototype::UNDEFINED) {
    type = ExteriorPrototype{Random::rand(0, static_cast<Quantity>(ExteriorPrototype::UNDEFINED))};
  }

  Size size = exteriorSize(type);
  entity::Exterior creation{Random::fromVec(world->locationNames) + " " + magic_enum::enum_name(type).data(), size};

  world->exteriors.emplace(entityCounter++, creation);
  return entityCounter;
}

Size Factory::connectorSize(ConnectorPrototype type) {
  Size size;
  switch (type) {
    case ConnectorPrototype::BRIDGE:
      size.width = 20;
      size.height = 4;
      break;
    case ConnectorPrototype::CAVE:
      size.width = 20;
      size.height = 30;
      break;
    case ConnectorPrototype::RIVER:
      size.width = 30;
      size.height = 15;
      break;
    case ConnectorPrototype::TUNNEL:
      size.width = 50;
      size.height = 10;
      break;
  }
  return size;
}

BuildingSpecs Factory::buildingSpecs(BuildingPrototype type) {
  BuildingSpecs specs;
  switch (type) {
    case BuildingPrototype::ARENA:
      specs.floors = 2;
      specs.size.width = 30;
      specs.size.height = 50;
      break;
    case BuildingPrototype::BARN:
      specs.floors = 2;
      specs.size.width = 10;
      specs.size.height = 50;
      break;
    case BuildingPrototype::HOME:
      specs.floors = 3;
      specs.size.width = 20;
      specs.size.height = 20;
      break;
    case BuildingPrototype::HOSPITAL:
      specs.floors = 8;
      specs.size.width = 50;
      specs.size.height = 60;
      break;
    case BuildingPrototype::LIBRARY:
      specs.floors = 3;
      specs.size.width = 25;
      specs.size.height = 35;
      break;
    case BuildingPrototype::MUSEUM:
      specs.floors = 1;
      specs.size.width = 40;
      specs.size.height = 20;
      break;
    case BuildingPrototype::SALOON:
      specs.floors = 1;
      specs.size.width = 35;
      specs.size.height = 35;
      break;
    case BuildingPrototype::SHOP:
      specs.floors = 1;
      specs.size.width = 20;
      specs.size.height = 10;
      break;
    case BuildingPrototype::SKYSCRAPER:
      specs.floors = 10;
      specs.size.width = 25;
      specs.size.height = 15;
      break;
    case BuildingPrototype::STORAGE:
      specs.floors = 1;
      specs.size.width = 18;
      specs.size.height = 53;
      break;
  }
  return specs;
}

Size Factory::exteriorSize(ExteriorPrototype type) {
  Size size;
  switch (type) {
    case ExteriorPrototype::CITY:
      size.width = 220;
      size.height = 180;
      break;
    case ExteriorPrototype::TOWN:
      size.width = 150;
      size.height = 120;
      break;
    case ExteriorPrototype::VILLAGE:
      size.width = 180;
      size.height = 180;
      break;
  }
  return size;
}

} // namespace model
