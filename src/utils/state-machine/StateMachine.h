//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <memory>

#include "utils/state-machine/MacroState.h"

using MacroStateId = uint8_t;
using MacroStateInfo = std::shared_ptr<MacroState>;

class StateMachine {

public:
  // Auxiliary types definition
  using LinkId = typename DirectedGraph<MacroStateId, MacroStateInfo, Transition>::EdgeId;

  void addMacroState(const MacroStateId macroStateId, std::shared_ptr<MacroState> macroState);
  void addTransition(MacroStateId origin, StateId destination, const Transition transition);
  virtual void whatsUp() = 0;
  void triggerTransition(const Transition transition);

protected:
  MacroStateId activeMacroState;
  DirectedGraph<MacroStateId, MacroStateInfo, Transition> macroStateNetwork;
};
