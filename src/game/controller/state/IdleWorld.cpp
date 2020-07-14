//
// Created by nolasco on 11/06/20.
//

#include "IdleWorld.h"

#include "game/controller/state/include/Transition.h"

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
    controller.strategize(World::activeCharacter);
    World::changeFocusedCharacter();
  };
  view::Printer::addToRoundReport(Verbose::INFO, "Comand me");
  triggerTransition(TERMINATE);
}

} // namespace controller