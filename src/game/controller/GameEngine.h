//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <set>

#include "game/controller/event/include/EventManager.h"
#include "game/model/World.h"
#include "game/model/handler/Handler.h"
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
  void updateViewVariables();

  Handler controller;
  std::set<StateId> mNeighbours;
  std::string mOptions;
  std::map<StateId, std::shared_ptr<StateMachine>> gameStates;
  EventManager eventManager;
};

} // namespace controller
