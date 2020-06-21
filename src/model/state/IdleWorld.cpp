//
// Created by nolasco on 11/06/20.
//

#include "IdleWorld.h"

enum STATES : StateId {
  SETUP = 1,
  EXECUTION,
  CLEANUP,
};

namespace model::state {

IdleWorld::IdleWorld() {
  addState(SETUP, "Load next character from list");
  addState(EXECUTION, "Handle character action");
  addState(CLEANUP, "Get next character");

  addTransition(STATE_STANDBYE, SETUP, 's');
  addTransition(SETUP, EXECUTION, '1');
  addTransition(EXECUTION, CLEANUP, '2');
  addTransition(CLEANUP, SETUP, '3');
}

void IdleWorld::whatsUp() {
  //  TODO: Loop through characters in current room
  // TODO: Make characters think
  auto activeCharacter = mWorld.character(mWorld.activeCharacter);

  mWorld.changeFocusedCharacter();
  if (GhostInTheShell::Player == activeCharacter.getGhost()) {
    mPrinter.directPrint("Comand me");
    endState();
  } else {
    mPrinter.directPrint("I'm gonna ride this on my own");
    continueToNext();
  }
}

void IdleWorld::continueToNext() {
  auto neighbours = stateNetwork.neighbours(activeState);
  auto transition = stateNetwork.getEdge(LinkId{activeState, neighbours[0]});
  triggerTransition(transition);
}

} // namespace model::state