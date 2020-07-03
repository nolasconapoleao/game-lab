//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <set>

#include "controller/handler/Controller.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class GameEngine : public StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void run() override;
  bool isTerminated();
  void addState(const StateId stateId, std::shared_ptr<StateMachine> state);

private:
  void manualTransition();
  void fillOptions();
  void handleUserInput();

  view::Printer mPrinter;
  Controller controller;
  std::set<StateId> mNeighbours;
  std::string mOptions;
  std::map<StateId, std::shared_ptr<StateMachine>> gameStates;
};

} // namespace model::state
