//
// Created by nolasco on 19/06/20.
//

#include "WorldMap.h"

#include "../../../../../../../../usr/lib/gcc/x86_64-w64-mingw32/9.2-win32/include/c++/set"

void WorldMap::addLocation(LocationId locationId, entity::Location location) {
  world.addNode(locationId, location);
}

void WorldMap::removeLocation(LocationId locationId) {
  world.removeNode(locationId);
}

entity::Location WorldMap::location(LocationId locationId) {
  return world.getNode(locationId);
}

Quantity WorldMap::numberOfLocations() {
  return world.numberOfNodes();
}

void WorldMap::linkLocations(LocationId start, LocationId end, Distance distance) {
  LinkId link{start, end};
  world.addEdge(link, distance);
}

void WorldMap::removelink(LocationId start, LocationId end) {
  LinkId link{start, end};
  world.removeEdge(link);
}

Distance WorldMap::distance(LocationId start, LocationId end) {
  LinkId link{start, end};
  return world.getEdge(link);
}

std::unordered_set<LocationId> WorldMap::neighbours(LocationId locationId) {
  return world.neighbours(locationId);
}
