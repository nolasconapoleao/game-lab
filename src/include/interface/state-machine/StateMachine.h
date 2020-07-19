//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "interface/graph/DirectedGraph.h"

using StateId = uint8_t;
using StateInfo = std::string;
using Transition = char;

class StateMachine {

public:
  // Auxiliary types definition
  using LinkId = typename DirectedGraph<StateId, StateInfo, Transition>::EdgeId;

  void addState(const StateId stateId, const StateInfo stateInfo);
  void addTransition(StateId origin, StateId destination, const Transition transition);
  StateId activeState() const;

  virtual void run() = 0;
  [[maybe_unused]] bool triggerTransition(const Transition transition);

protected:
  StateId mActiveState;
  DirectedGraph<StateId, StateInfo, Transition> stateNetwork;
};
