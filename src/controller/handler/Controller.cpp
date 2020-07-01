//
// Created by nolasco on 20/06/20.
//

#include "Controller.h"

#include "model/World.h"
#include "view/include/StreamConverter.h"

void Controller::updateViewVariables() {
  mPrinter.resetLists();

  if (!world.characters.empty()) {
    mPrinter.addToHud(Verbose::INFO, fullPrint(world.character(world.activeCharacter)));
  }
  mPrinter.addToScene(Verbose::INFO, printScene(world));
}

void Controller::battle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId) {
  auto &attacker = world.character(attackerId);
  auto &attacked = world.character(attackedId);

  handleAttack(attacker, attacked);
  if (attacked.getStats().hp == 0) {
    dropAllItems(attackedId, battleGroundId);
  }
}

void Controller::dropAllItems(CharacterId characterId, LocationId locationId) {
  const auto items = world.itemsOfCharacter(characterId);
  // TODO: resolve this once world returns ids instead of objects
  //  for (auto item : items) {
  //    changeItemOwner(*item.get(), OwnerType::LOCATION, locationId);
  //  }
}

void Controller::strategize(CharacterId characterId) {
  // TODO: use character inteligence, occupation, health, location
  const auto character = world.character(characterId);

  if (character.getStats().hp > 2) {
    battle(characterId, characterId, world.activeLocation);
  }
}
