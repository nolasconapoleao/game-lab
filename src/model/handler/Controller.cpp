//
// Created by nolasco on 20/06/20.
//

#include "Controller.h"

#include <model/World.h>

#include "model/World.h"
#include "view/include/StreamConverter.h"

void Controller::updateViewVariables() {
  view::Printer::resetLists();

  if (!World::characters.empty()) {
    view::Printer::addToHud(Verbose::INFO, fullPrint(World::character(World::activeCharacter)));
  }
  view::Printer::addToScene(Verbose::INFO, printScene());
}

void Controller::strategize(CharacterId characterId) {
  // TODO: use character inteligence, occupation, health, location
  const auto character = World::character(characterId);

  if (character.getStats().hp > 2) {
    battle(characterId, characterId, World::activeLocation);
  }
}
