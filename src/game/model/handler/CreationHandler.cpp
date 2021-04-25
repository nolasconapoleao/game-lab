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

    mWorld->neighbours.emplace(newSeed, seed);
    mWorld->neighbours.emplace(seed, newSeed);
  }
  seed = createNeighbour(seed, ThreatLevel::VETERAN);
}

LocationId Handler::createGroundZero() {
  auto playerId = mFactory->createCharacter(ThreatLevel::NOVICE);
  fillInventory(playerId, ThreatLevel::NOVICE);
  mWorld->characters.find(playerId)->second.info.ghost = Ghost::PLAYER;

  auto locationId = mFactory->createLocation();
  fillLocation(locationId, ThreatLevel::NOVICE);
  mWorld->locatedIn[playerId] = locationId;
  return locationId;
}

LocationId Handler::createNeighbour(const LocationId locationId, const ThreatLevel threat) {
  auto connectorId = mFactory->createConnector();
  fillLocation(connectorId, threat);
  mWorld->neighbours.emplace(locationId, connectorId);
  mWorld->neighbours.emplace(connectorId, locationId);

  auto neighbourId = mFactory->createLocation();
  fillLocation(neighbourId, threat);
  fillExterior(neighbourId, threat);
  mWorld->neighbours.emplace(connectorId, neighbourId);
  mWorld->neighbours.emplace(neighbourId, connectorId);
  return neighbourId;
}

void Handler::fillExterior(const LocationId locationId, const ThreatLevel threat) {
  fillFloor(locationId, threat);
  for (auto k = 0; k < creationSpecs(threat).num_buildings; k++) {
    auto interiorId = mFactory->createBuilding();
    fillLocation(interiorId, threat);
    mWorld->locatedIn.emplace(locationId, interiorId);
    mWorld->locatedIn.emplace(interiorId, locationId);
  }
}

void Handler::fillLocation(const LocationId locationId, const ThreatLevel threat) {
  for (auto k = 0; k < creationSpecs(threat).num_characters; k++) {
    auto characterId = mFactory->createCharacter(threat);
    mWorld->locatedIn.emplace(characterId, locationId);
    fillInventory(characterId, threat);
  }
  for (auto k = 0; k < creationSpecs(threat).num_structures; k++) {
    auto structureId = mFactory->createStructure();
    mWorld->locatedIn.emplace(structureId, locationId);
  }
}

void Handler::fillInventory(const CharacterId characterId, const ThreatLevel threat) {
  for (auto k = 0; k < creationSpecs(threat).num_character_consumables; k++) {
    auto itemId = mFactory->createEquippable();
    mWorld->locatedIn.emplace(itemId, characterId);
  }
  for (auto k = 0; k < creationSpecs(threat).num_character_equippables; k++) {
    auto itemId = mFactory->createConsumable();
    mWorld->locatedIn.emplace(itemId, characterId);
  }
}

void Handler::fillFloor(const LocationId locationId, const ThreatLevel threat) {
  for (auto k = 0; k < creationSpecs(threat).num_exterior_consumables; k++) {
    auto itemId = mFactory->createEquippable();
    mWorld->locatedIn.emplace(itemId, locationId);
  }
  for (auto k = 0; k < creationSpecs(threat).num_exterior_equippables; k++) {
    auto itemId = mFactory->createConsumable();
    mWorld->locatedIn.emplace(itemId, locationId);
  }
}

} // namespace model
