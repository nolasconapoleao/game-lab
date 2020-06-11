//
// Created by nolasco on 07/06/20.
//

#include "MacroState.h"

MacroState::MacroState() : activeState(STATE_STANDBYE) {
  addState(STATE_STANDBYE, "Macro state is on hold");
}

void MacroState::addState(StateId stateId, StateInfo stateInfo) {
  stateNetwork.addNode(stateId, stateInfo);
}

void MacroState::addTransition(StateId origin, StateId destination, Transition transition) {
  LinkId link{origin, destination};
  stateNetwork.addEdge(link, transition);
}

void MacroState::startState() {
  triggerTransition('s');
}

void MacroState::triggerTransition(Transition transition) {
  const auto neighbourStates = stateNetwork.neighbours(activeState);

  for (const auto neighbour : neighbourStates) {
    LinkId link{activeState, neighbour};
    if (stateNetwork.getEdge(link) == transition) {
      advanceToState(neighbour);
      return;
    }
  }

  return;
}

void MacroState::endState() {
  activeState = STATE_STANDBYE;
}

void MacroState::advanceToState(StateId newState) {
  activeState = newState;
}

bool MacroState::isStandingBye() {
  return activeState == STATE_STANDBYE;
}
