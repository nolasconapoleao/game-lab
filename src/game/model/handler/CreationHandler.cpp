//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "libs/constants/gameconstants.h"
#include "model/World.h"
#include "model/factory/Factory.h"

using namespace gameconstants;

namespace model {

void Handler::createWorld() {
  auto seed = createGroundZero();
  auto newSeed = createNeighbour(seed, ThreatLevel::SCARECROW);

  for (auto k = 0; k < creationSpecs(ThreatLevel::NOVICE).num_exteriors; k++) {
    seed = createNeighbour(newSeed, ThreatLevel::NOVICE);
    createNeighbour(newSeed, ThreatLevel::NOVICE);
    newSeed = createNeighbour(newSeed, ThreatLevel::ACE);

    world->neighbours.emplace(newSeed, seed);
    world->neighbours.emplace(seed, newSeed);
  }
  seed = createNeighbour(seed, ThreatLevel::VETERAN);
}

LocationId Handler::createGroundZero() {
  auto playerId = factory->createCharacter(ThreatLevel::NOVICE);
  fillInventory(playerId, ThreatLevel::NOVICE);
  world->characters.find(playerId)->second.info.ghost = Ghost::PLAYER;

  auto locationId = factory->createLocation();
  fillLocation(locationId, ThreatLevel::NOVICE);
  world->locatedIn[playerId] = locationId;
  return locationId;
}

LocationId Handler::createNeighbour(const LocationId locationId, const ThreatLevel threat) {
  auto connectorId = factory->createConnector();
  fillLocation(connectorId, threat);
  world->neighbours.emplace(locationId, connectorId);
  world->neighbours.emplace(connectorId, locationId);

  auto neighbourId = factory->createLocation();
  fillLocation(neighbourId, threat);
  fillExterior(neighbourId, threat);
  world->neighbours.emplace(connectorId, neighbourId);
  world->neighbours.emplace(neighbourId, connectorId);
  return neighbourId;
}

void Handler::fillExterior(const LocationId locationId, const ThreatLevel threat) {
  fillFloor(locationId, threat);
  for (auto k = 0; k < creationSpecs(threat).num_buildings; k++) {
    auto interiorId = factory->createBuilding();
    fillLocation(interiorId, threat);
    world->locatedIn.emplace(locationId, interiorId);
    world->locatedIn.emplace(interiorId, locationId);
  }
}

void Handler::fillLocation(const LocationId locationId, const ThreatLevel threat) {
  for (auto k = 0; k < creationSpecs(threat).num_characters; k++) {
    auto characterId = factory->createCharacter(threat);
    world->locatedIn.emplace(characterId, locationId);
    fillInventory(characterId, threat);
  }
  for (auto k = 0; k < creationSpecs(threat).num_structures; k++) {
    auto structureId = factory->createStructure();
    world->locatedIn.emplace(structureId, locationId);
  }
}

void Handler::fillInventory(const CharacterId characterId, const ThreatLevel threat) {
  for (auto k = 0; k < creationSpecs(threat).num_character_consumables; k++) {
    auto itemId = factory->createEquippable();
    world->locatedIn.emplace(itemId, characterId);
  }
  for (auto k = 0; k < creationSpecs(threat).num_character_equippables; k++) {
    auto itemId = factory->createConsumable();
    world->locatedIn.emplace(itemId, characterId);
  }
}

void Handler::fillFloor(const LocationId locationId, const ThreatLevel threat) {
  for (auto k = 0; k < creationSpecs(threat).num_exterior_consumables; k++) {
    auto itemId = factory->createEquippable();
    world->locatedIn.emplace(itemId, locationId);
  }
  for (auto k = 0; k < creationSpecs(threat).num_exterior_equippables; k++) {
    auto itemId = factory->createConsumable();
    world->locatedIn.emplace(itemId, locationId);
  }
}

} // namespace model
