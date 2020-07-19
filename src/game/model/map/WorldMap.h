//
// Created by nolasco on 19/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "interface/graph/UndirectedGraph.h"
#include "model/entity/Location.h"

class WorldMap {
public:
  // Auxiliary types definition
  using LinkId = typename UndirectedGraph<LocationId, entity::Location, Distance>::EdgeId;

  void addLocation(const LocationId locationId, entity::Location location);
  void removeLocation(const LocationId locationId);
  entity::Location location(LocationId locationId);
  Quantity numberOfLocations();

  void linkLocations(const LocationId start, const LocationId end, Distance distance);
  void removelink(const LocationId start, const LocationId end);
  Distance distance(const LocationId start, const LocationId end);
  std::unordered_set<LocationId> neighbours(LocationId locationId);

private:
  UndirectedGraph<LocationId, entity::Location, Distance> map;
};
