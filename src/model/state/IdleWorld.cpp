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
  auto activeCharacter = mWorld.character(mWorld.activeCharacter);

  mWorld.changeFocusedCharacter();
  if (GhostInTheShell::Player == activeCharacter.getGhost()) {
    mPrinter.directPrint("Comand me");
    triggerTransition(TERMINATE);
  } else {
    mPrinter.directPrint("I'm gonna ride this on my own");
    controller.strategize(mWorld.activeCharacter);
  }
}

} // namespace model::state