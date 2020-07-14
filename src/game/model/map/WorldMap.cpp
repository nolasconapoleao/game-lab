//
// Created by nolasco on 19/06/20.
//

#include "WorldMap.h"

#include "set"

void WorldMap::addLocation(LocationId locationId, entity::Location location) {
  map.addNode(locationId, location);
}

void WorldMap::removeLocation(LocationId locationId) {
  map.removeNode(locationId);
}

entity::Location WorldMap::location(LocationId locationId) {
  return map.getNode(locationId);
}

Quantity WorldMap::numberOfLocations() {
  return map.numberOfNodes();
}

void WorldMap::linkLocations(LocationId start, LocationId end, Distance distance) {
  LinkId link{start, end};
  map.addEdge(link, distance);
}

void WorldMap::removelink(LocationId start, LocationId end) {
  LinkId link{start, end};
  map.removeEdge(link);
}

Distance WorldMap::distance(LocationId start, LocationId end) {
  LinkId link{start, end};
  return map.getEdge(link);
}

std::unordered_set<LocationId> WorldMap::neighbours(LocationId locationId) {
  return map.neighbours(locationId);
}
