//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "utils/graph/DirectedGraph.h"

using StateId = uint8_t;
using StateInfo = std::string;
using Transition = char;

constexpr StateId STATE_STANDBYE = 0;

class MacroState {

public:
  // Auxiliary types definition
  using LinkId = typename DirectedGraph<StateId, StateInfo, Transition>::EdgeId;

  MacroState();
  void addState(const StateId stateId, const StateInfo stateInfo);
  void addTransition(StateId origin, StateId destination, const Transition transition);
  virtual void start() = 0;
  virtual void whatsUp() = 0;
  void triggerTransition(const Transition transition);
  bool isStandingBye();

private:
  void advanceToState(const StateId newState);

protected:
  StateId activeState;
  DirectedGraph<StateId, StateInfo, Transition> stateNetwork;
};
