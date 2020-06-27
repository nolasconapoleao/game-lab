//
// Created by nolasco on 11/06/20.
//

#include "IdleWorld.h"

#include "model/state/include/Substate.h"
#include "model/state/include/Transition.h"

enum STATES : StateId {
  SETUP = 1,
  EXECUTION,
  CLEANUP,
};

namespace model::state {

IdleWorld::IdleWorld() {
  createNetwork();
}

void IdleWorld::fillStateOption() {
  // Intentionally left blank
}

void IdleWorld::execute() {
  //  TODO: Loop through characters in current room
  // TODO: Make characters think
  auto activeCharacter = mWorld.character(mWorld.activeCharacter);

  mWorld.changeFocusedCharacter();
  if (GhostInTheShell::Player == activeCharacter.getGhost()) {
    mPrinter.directPrint("Comand me");
    triggerTransition(Transitions::TERMINATE);
  } else {
    mPrinter.directPrint("I'm gonna ride this on my own");
  }
}

} // namespace model::state