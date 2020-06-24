//
// Created by nolasco on 11/06/20.
//

#include "StartWorld.h"

enum STATES : StateId {
  CREATE_WORLD = 1,
};

namespace model::state {

StartWorld::StartWorld() {
  addState(CREATE_WORLD, "Create world map");

  addTransition(STATE_STANDBYE, CREATE_WORLD, 's');
  addTransition(CREATE_WORLD, STATE_STANDBYE, 'b');
}

void StartWorld::whatsUp() {
  switch (activeState) {
    case CREATE_WORLD: {
      factory.createWorld();
    }
  }
  continueToNext();
}

void StartWorld::continueToNext() {
  auto neighbours = stateNetwork.neighbours(activeState);
  auto transition = stateNetwork.getEdge(LinkId{activeState, neighbours[0]});
  triggerTransition(transition);
}

} // namespace model::state