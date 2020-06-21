//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <vector>

#include "controller/factory/include/LocationPrototype.h"
#include "model/entity/Location.h"

class LocationFactory {
public:
  LocationFactory();
  entity::Location generateLocation(const LocationCategory type);
  entity::Location createLocation(const LocationPrototype type);

private:
  std::vector<LocationPrototype> interiorPool;
  std::vector<LocationPrototype> exteriorPool;
  std::vector<LocationPrototype> connectorPool;
};
