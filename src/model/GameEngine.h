//
// Created by nolasco on 10/06/20.
//

#pragma once

#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

constexpr StateId TERMINATE = 0;

namespace model::state {

class GameEngine : StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void whatsUp() override;
  bool isTerminated();

private:
  void continueToNext();
  void fillOptions();
  void handleUserInput();
  void startNextMacroState();

  view::Printer mPrinter;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
};

} // namespace model::state
