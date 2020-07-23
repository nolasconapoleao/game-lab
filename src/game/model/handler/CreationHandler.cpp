//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"
#include "model/factory/Factory.h"

namespace model {

constexpr Quantity NUM_EXTERIORS = 3;

void Handler::createWorld() {
  auto playerId = factory->createCharacter(ThreatLevel::NOVICE);
  fillInventory(playerId, ThreatLevel::NOVICE);
  world->characters.find(playerId)->second.info.ghost = Ghost::PLAYER;

  auto seed = factory->createLocation();
  auto newSeed = createNeighbour(seed, ThreatLevel::SCARECROW);

  for (auto k = 0; k < NUM_EXTERIORS; k++) {
    seed = createNeighbour(newSeed, ThreatLevel::SCARECROW);
    createNeighbour(newSeed, ThreatLevel::SCARECROW);
    newSeed = createNeighbour(newSeed, ThreatLevel::NOVICE);

    world->neighbours.emplace(newSeed, seed);
    world->neighbours.emplace(seed, newSeed);
  }
  seed = createNeighbour(seed, ThreatLevel::ACE);
}

LocationId Handler::createNeighbour(const LocationId locationId, const ThreatLevel threat) {
  auto connectorId = factory->createConnector();
  fillLocation(connectorId, threat);
  world->neighbours.emplace(locationId, connectorId);
  world->neighbours.emplace(connectorId, locationId);

  auto neighbourId = factory->createLocation();
  fillLocation(neighbourId, threat);
  fillExterior(neighbourId, threat);
  world->neighbours.emplace(locationId, neighbourId);
  world->neighbours.emplace(neighbourId, locationId);
}

void Handler::fillExterior(const LocationId locationId, const ThreatLevel threat) {
  for (auto k = 0; k < (Quantity)threat; k++) {
    auto interiorId = factory->createBuilding();
    fillLocation(interiorId, threat);
    world->locatedIn.emplace(locationId, interiorId);
    world->locatedIn.emplace(interiorId, locationId);
  }
  auto structureId = factory->createStructure();
  world->locatedIn.emplace(structureId, locationId);
}

void Handler::fillLocation(const LocationId locationId, const ThreatLevel threat) {
  for (auto k = 0; k < (Quantity)threat; k += 4) {
    auto characterId = factory->createCharacter(threat);
    world->possessions.emplace(characterId, locationId);
    fillInventory(characterId, threat);
  }
}

void Handler::fillInventory(const CharacterId characterId, const ThreatLevel threat) {
  auto itemId = factory->createConsumable();

  switch (threat) {
    case ThreatLevel::SCARECROW:
      world->possessions.emplace(itemId, characterId);
      [[fallthrough]];
    case ThreatLevel::NOVICE:
      itemId = factory->createWeapon();
      world->possessions.emplace(itemId, characterId);
      [[fallthrough]];
    case ThreatLevel::ACE:
      itemId = factory->createEquipment();
      world->possessions.emplace(itemId, characterId);
      [[fallthrough]];
    case ThreatLevel::VETERAN:
      itemId = factory->createStaff();
      world->possessions.emplace(itemId, characterId);
      [[fallthrough]];
    case ThreatLevel::MONSTER:
      itemId = factory->createStaff();
      world->possessions.emplace(itemId, characterId);
      [[fallthrough]];
    case ThreatLevel::GOD:
      itemId = factory->createStaff();
      world->possessions.emplace(itemId, characterId);
      break;
  }
}

} // namespace model
