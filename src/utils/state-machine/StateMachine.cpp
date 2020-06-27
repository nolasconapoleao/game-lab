//
// Created by nolasco on 07/06/20.
//

#include "StateMachine.h"

StateMachine::StateMachine() {
}

void StateMachine::addState(StateId stateId, StateInfo stateInfo) {
  stateNetwork.addNode(stateId, stateInfo);
}

StateId StateMachine::activeState() const {
  return mActiveState;
}

void StateMachine::addTransition(StateId origin, StateId destination, Transition transition) {
  LinkId link{origin, destination};
  stateNetwork.addEdge(link, transition);
}

void StateMachine::triggerTransition(Transition transition) {
  const auto neighbourStates = stateNetwork.neighbours(mActiveState);

  for (const auto neighbour : neighbourStates) {
    LinkId link{mActiveState, neighbour};
    if (stateNetwork.getEdge(link) == transition) {
      mActiveState = neighbour;
      return;
    }
  }

  std::cerr << "Invalid transition.\n";
  return;
}
