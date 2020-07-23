//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <set>

#include "interface//event/EventManager.h"
#include "interface/state-machine/StateMachine.h"
#include "model/World.h"
#include "model/handler/Handler.h"
#include "view/Printer.h"

namespace controller {

class GameEngine : public StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void run() override;
  bool isTerminated();
  void addState(const StateId stateId, std::shared_ptr<StateMachine> state);

  // Active stream-aux
  void loadNextCharacter();
  CharacterId activeCharacter;
  void updateCharacterQueue();
  std::unordered_set<LocationId> activeLocations();
  std::priority_queue<std::pair<int, CharacterId>> characterQueue;

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
