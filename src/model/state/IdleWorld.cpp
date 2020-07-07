//
// Created by nolasco on 11/06/20.
//

#include "IdleWorld.h"

#include "model/state/include/Transition.h"

namespace model::state {

IdleWorld::IdleWorld() {
  createNetwork();
}

void IdleWorld::fillStateOption() {
  // Intentionally left blank
}

void IdleWorld::execute() {
  mWorld.changeFocusedCharacter();
  // FIXME: Hic sunt dracones - if no character with player ghost exists
  while (GhostInTheShell::Player != mWorld.character(mWorld.activeCharacter).getGhost()) {
    mPrinter.addToRoundReport(Verbose::INFO, "I'm gonna ride this on my own");
    controller.strategize(mWorld.activeCharacter);
    mWorld.changeFocusedCharacter();
  };
  mPrinter.addToRoundReport(Verbose::INFO, "Comand me");
  triggerTransition(TERMINATE);
}

} // namespace model::state