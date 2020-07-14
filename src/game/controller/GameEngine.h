//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <set>

#include "game/model/handler/Controller.h"
#include "game/view/Printer.h"
#include "state-machine/StateMachine.h"

namespace controller {

class GameEngine : public StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void run() override;
  bool isTerminated();
  void addState(const StateId stateId, std::shared_ptr<StateMachine> state);

private:
  void fillOptions();
  void handleUserInput();

  Controller controller;
  std::set<StateId> mNeighbours;
  std::string mOptions;
  std::map<StateId, std::shared_ptr<StateMachine>> gameStates;
};

} // namespace controller
