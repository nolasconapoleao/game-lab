//
// Created by nolasco on 07/06/20.
//

#include "StateMachine.h"

void StateMachine::addMacroState(const MacroStateId macroStateId, std::shared_ptr<MacroState> macroState) {
  macroStateNetwork.addNode(macroStateId, macroState);
}

void StateMachine::addTransition(MacroStateId origin, StateId destination, Transition transition) {
  LinkId link{origin, destination};
  macroStateNetwork.addEdge(link, transition);
}

void StateMachine::triggerTransition(Transition transition) {
  const auto neighbourStates = macroStateNetwork.neighbours(activeMacroState);

  for (const auto neighbour : neighbourStates) {
    LinkId link{activeMacroState, neighbour};
    if (macroStateNetwork.getEdge(link) == transition) {
      activeMacroState = neighbour;
      return;
    }
  }

  return;
}
