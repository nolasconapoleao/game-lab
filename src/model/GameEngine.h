//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>

#include "controller/handler/Controller.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class GameEngine : StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void run() override;
  bool isTerminated();
  void addState(const StateId stateId, std::shared_ptr<StateMachine> state);

private:
  void loadNextState();
  void automaticTransition();
  void manualTransition();
  void fillOptions();
  void handleUserInput();
  std::shared_ptr<StateMachine> getState(const StateId stateId);

  view::Printer mPrinter;
  Controller entityHandler;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
  std::map<StateId, std::shared_ptr<StateMachine>> gameStates;
};

} // namespace model::state
