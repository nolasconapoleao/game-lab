//
// Created by nolasco on 20/06/20.
//

#include "EntityHandler.h"

#include "model/World.h"
#include "view/include/StreamConverter.h"

void EntityHandler::updateViewVariables() {
  mPrinter.resetLists();

  if (!world.characters.empty()) {
    mPrinter.addToHud(Verbose::INFO, fullPrint(world.character(world.activeCharacter)));
  }
  mPrinter.addToScene(Verbose::INFO, printScene(world));
}

void EntityHandler::battle(const CharacterId attackerId, const CharacterId attackedId,
                           const LocationId battleGroundId) {
  auto &attacker = world.character(attackerId);
  auto &attacked = world.character(attackedId);

  combatHandler.handleAttack(attacker, attacked);
  if (attacked.getStats().hp == 0) {
    dropAllItems(attackedId, battleGroundId);
  }
}

void EntityHandler::characterGoesTo(const CharacterId &characterId, LocationId locationId) {
  entity::Character &character = world.character(characterId);
  travelHandler.characterGoesTo(character, locationId);
}

void EntityHandler::dropAllItems(CharacterId characterId, LocationId locationId) {
  const auto items = world.itemsOfCharacter(characterId);
  for (auto item : items) {
    itemHandler.changeItemOwner(*item.get(), OwnerType::LOCATION, locationId);
  }
}
