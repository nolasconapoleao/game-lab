//
// Created by nolasco on 10/06/20.
//

#pragma once

#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class GameEngine : StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void whatsUp() override;
  bool isTerminated();

private:
  void loadAnotherMacroState();
  void automaticTransition();
  void manualTransition();
  void fillOptions();
  void handleUserInput();
  std::shared_ptr<MacroState> getMacroState(const MacroStateId macroStateId);

  view::Printer mPrinter;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
};

} // namespace model::state
