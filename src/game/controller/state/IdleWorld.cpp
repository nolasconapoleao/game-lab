//
// Created by nolasco on 11/06/20.
//

#include "IdleWorld.h"

#include "game/controller/state/include/Transition.h"
#include "game/view/cases/Logger.h"

namespace controller {

IdleWorld::IdleWorld() {
  createNetwork();
}

void IdleWorld::fillStateOption() {
  // Intentionally left blank
}

void IdleWorld::execute() {
  World::changeFocusedCharacter();
  // FIXME: Hic sunt dracones - if no character with player ghost exists
  while (GhostInTheShell::Player != World::character(World::activeCharacter).getGhost()) {
    view::Printer::addToRoundReport(Verbose::INFO, "I'm gonna ride this on my own");
    strategize(World::activeCharacter);
    World::changeFocusedCharacter();
  };
  view::Printer::addToRoundReport(Verbose::INFO, "Comand me");
  triggerTransition(TERMINATE);
}

void IdleWorld::strategize(CharacterId characterId) {
  // TODO: use character inteligence, occupation, health, location
  const auto character = World::character(characterId);

  if (character.getStats().hp > 2) {
    const auto result = mHandler.battle(characterId, characterId, World::activeLocation);
    logBattle(characterId, characterId, World::activeLocation, result);
  }
}

} // namespace controller