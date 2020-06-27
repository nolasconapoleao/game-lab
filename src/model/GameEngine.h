//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <memory>

#include "controller/handler/EntityHandler.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class GameEngine : StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void run() override;
  bool isTerminated();

private:
  void loadAnotherMacroState();
  void automaticTransition();
  void manualTransition();
  void fillOptions();
  void handleUserInput();
  void addTransitionWithReturn();
  std::shared_ptr<StateMachine> getState(const StateId stateId);

  view::Printer mPrinter;
  EntityHandler entityHandler;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
  std::vector<std::shared_ptr<StateMachine>> gameStates;
};

} // namespace model::state
