//
// Created by nolasco on 21/07/20.
//

#include <magic_enum/include/magic_enum.hpp>

#include "Factory.h"
#include "model/World.h"
#include "random/Random.h"

namespace model {
LocationId Factory::createConnector(ConnectorType type) {
  if (type == ConnectorType::UNDEFINED) {
    type = ConnectorType{Random::rand(0, static_cast<Quantity>(ConnectorType::UNDEFINED) - 1)};
  }

  Size size = connectorSize(type);
  entity::Exterior creation{Random::fromVec(mWorld->locationNames) + " " + magic_enum::enum_name(type).data(), size};

  mWorld->exteriors.emplace(++entityCounter, creation);
  return entityCounter;
}

LocationId Factory::createBuilding(BuildingType type) {
  if (type == BuildingType::UNDEFINED) {
    type = BuildingType{Random::rand(0, static_cast<Quantity>(BuildingType::UNDEFINED) - 1)};
  }

  auto [size, floors] = buildingSpecs(type);
  entity::Building creation{Random::fromVec(mWorld->locationNames) + " " + magic_enum::enum_name(type).data(), type,
                            size, floors};

  mWorld->buildings.emplace(++entityCounter, creation);
  return entityCounter;
}

LocationId Factory::createLocation(ExteriorType type) {
  if (type == ExteriorType::UNDEFINED) {
    type = ExteriorType{Random::rand(0, static_cast<Quantity>(ExteriorType::UNDEFINED) - 1)};
  }

  Size size = exteriorSize(type);
  entity::Exterior creation{Random::fromVec(mWorld->locationNames) + " " + magic_enum::enum_name(type).data(), size};

  mWorld->exteriors.emplace(++entityCounter, creation);
  return entityCounter;
}

constexpr Size Factory::connectorSize(const ConnectorType type) {
  Size size{};
  switch (type) {
    case ConnectorType::BRIDGE:
      size.width = 20;
      size.height = 4;
      break;
    case ConnectorType::CAVE:
      size.width = 20;
      size.height = 30;
      break;
    case ConnectorType::RIVER:
      size.width = 30;
      size.height = 15;
      break;
    case ConnectorType::TUNNEL:
      size.width = 50;
      size.height = 10;
      break;
    case ConnectorType::UNDEFINED:
      throw std::invalid_argument("Invalid connector action");
  }
  return size;
}

constexpr BuildingSpecs Factory::buildingSpecs(const BuildingType type) {
  BuildingSpecs specs{};
  switch (type) {
    case BuildingType::ARENA:
      specs.floors = 2;
      specs.size.width = 30;
      specs.size.height = 50;
      break;
    case BuildingType::BARN:
      specs.floors = 2;
      specs.size.width = 10;
      specs.size.height = 50;
      break;
    case BuildingType::HOME:
      specs.floors = 3;
      specs.size.width = 20;
      specs.size.height = 20;
      break;
    case BuildingType::HOSPITAL:
      specs.floors = 8;
      specs.size.width = 50;
      specs.size.height = 60;
      break;
    case BuildingType::LIBRARY:
      specs.floors = 3;
      specs.size.width = 25;
      specs.size.height = 35;
      break;
    case BuildingType::MUSEUM:
      specs.floors = 1;
      specs.size.width = 40;
      specs.size.height = 20;
      break;
    case BuildingType::SALOON:
      specs.floors = 1;
      specs.size.width = 35;
      specs.size.height = 35;
      break;
    case BuildingType::SHOP:
      specs.floors = 1;
      specs.size.width = 20;
      specs.size.height = 10;
      break;
    case BuildingType::SKYSCRAPER:
      specs.floors = 10;
      specs.size.width = 25;
      specs.size.height = 15;
      break;
    case BuildingType::STORAGE:
      specs.floors = 1;
      specs.size.width = 18;
      specs.size.height = 53;
      break;
    case BuildingType::UNDEFINED:
      throw std::invalid_argument("Invalid building action");
  }
  return specs;
}

constexpr Size Factory::exteriorSize(const ExteriorType type) {
  Size size{};
  switch (type) {
    case ExteriorType::CITY:
      size.width = 220;
      size.height = 180;
      break;
    case ExteriorType::TOWN:
      size.width = 150;
      size.height = 120;
      break;
    case ExteriorType::VILLAGE:
      size.width = 180;
      size.height = 180;
      break;
    case ExteriorType::UNDEFINED:
      throw std::invalid_argument("Invalid exterior action");
  }
  return size;
}

} // namespace model
