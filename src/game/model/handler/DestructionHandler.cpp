//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

void Handler::destroyWorld() {
  world->characters.clear();
  world->consumables.clear();
  world->equipables.clear();
  world->exteriors.clear();
  world->buildings.clear();
  world->structures.clear();
  world->teams.clear();

  world->neighbours.clear();
  world->possessions.clear();
  world->locatedIn.clear();
  world->memberships.clear();
}

void Handler::demolishBuilding(const LocationId buildingId) {
}

void Handler::demolishStructure(const StructureId structureId) {
}

} // namespace model
