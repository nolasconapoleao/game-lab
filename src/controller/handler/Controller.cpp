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

void Controller::strategize(CharacterId characterId) {
  // TODO: use character inteligence, occupation, health, location
  const auto character = world.character(characterId);

  if (character.getStats().hp > 2) {
    battle(characterId, characterId, world.activeLocation);
  }
}
