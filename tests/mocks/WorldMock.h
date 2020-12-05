//
// Created by nolasco on 02/06/20.
//

#pragma once

#include "GameConstant.h"
#include "model/World.h"

namespace testHelper {

std::shared_ptr<model::World> createWorldMock() {
  model::World world;
  world.characters.emplace(cCharacterId, cCharacter);
  world.characters.emplace(cCharacter2Id, cCharacter);
  world.consumables.emplace(cConsumableId, cConsumable);
  world.equippables.emplace(cEquipableId, cEquipable);
  world.equippables.emplace(cEquipable2Id, cEquipable);
  world.structures.emplace(cStructureId, cStructure);
  world.buildings.emplace(cBuildingId, cBuilding);
  world.exteriors.emplace(cExteriorId, cExterior);
  world.exteriors.emplace(cExterior2Id, cExterior);
  world.teams.emplace(cTeamId, cTeam);
  world.neighbours.emplace(cExteriorId, cExterior2Id);
  world.locatedIn.emplace(cConsumableId, cCharacterId);
  world.locatedIn.emplace(cEquipableId, cCharacter2Id);
  world.locatedIn.emplace(cEquipable2Id, cExteriorId);
  world.locatedIn.emplace(cStructureId, cExteriorId);
  world.locatedIn.emplace(cBuildingId, cExteriorId);
  world.memberships.emplace(cCharacterId, cTeamId);
  world.memberships.emplace(cCharacter2Id, cTeamId);
  world.characterNames.emplace_back("character name");
  world.locationNames.emplace_back("location name");
  world.teamNames.emplace_back("team name");

  return std::move(std::make_shared<model::World>(world));
}

} // namespace testHelper
