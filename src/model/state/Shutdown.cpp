//
// Created by nolasco on 21/06/20.
//

#include "Shutdown.h"

enum STATES : StateId {
  SAY_BYE = 1,
};

namespace model::state {

Shutdown::Shutdown() {
  addState(SAY_BYE, "Say goodbye to player in console");

  addTransition(STATE_STANDBYE, SAY_BYE, 's');
  addTransition(SAY_BYE, STATE_STANDBYE, 'b');
}

void Shutdown::whatsUp() {
  switch (activeState) {
    case SAY_BYE: {
      mPrinter.directPrint("Game over.");
    }
  }
  continueToNext();
}

void Shutdown::continueToNext() {
  auto neighbours = stateNetwork.neighbours(activeState);
  auto transition = stateNetwork.getEdge(LinkId{activeState, neighbours[0]});
  triggerTransition(transition);
}

} // namespace model::state