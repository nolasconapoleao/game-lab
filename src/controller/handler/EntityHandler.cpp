//
// Created by nolasco on 20/06/20.
//

#include "EntityHandler.h"

#include "model/World.h"
#include "view/include/StreamConverter.h"

void EntityHandler::updateViewVariables() {
  mPrinter.resetLists();

  const auto characters = world.charactersInLocation(0);
  for (const auto character : characters) {
    mPrinter.addToHud(Verbose::INFO, minimalPrint(character));
  }
  mPrinter.addToScene(Verbose::INFO, printScene(world));
}

void EntityHandler::attack(const CharacterId attackerId, const CharacterId attackedId) {
  auto attacker = world.character(attackerId);
  auto attacked = world.character(attackedId);
  combatHandler.handleAttack(attacker, attacked);
}

void EntityHandler::characterGoesTo(const CharacterId &characterId, LocationId locationId) {
  entity::Character &character = world.character(characterId);
  travelHandler.characterGoesTo(character, locationId);
}
