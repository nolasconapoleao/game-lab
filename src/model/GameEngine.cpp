//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>

#include "input/Input.h"
#include "model/state/Attack.h"
#include "model/state/Empty.h"
#include "model/state/Example.h"
#include "model/state/IdleWorld.h"
#include "model/state/Shutdown.h"
#include "model/state/Start.h"
#include "model/state/Tutorial.h"
#include "model/state/Walk.h"
#include "model/state/include/Menu.h"
#include "model/state/include/Substate.h"
#include "model/state/include/Transition.h"

enum MACRO_STATES : StateId {
  example = 0,
  idleWorld,
  attack,
  startWorld,
  tutorial,
  walk,
  skip,
  playerTurn,
  endTurn,
  shutdown,
};

namespace model::state {
GameEngine::GameEngine() {
  mActiveState = startWorld;

  addState(example, std::make_shared<Example>());
  addState(idleWorld, std::make_shared<IdleWorld>());
  addState(shutdown, std::make_shared<Shutdown>());
  addState(startWorld, std::make_shared<Start>());
  addState(tutorial, std::make_shared<Tutorial>());
  addState(walk, std::make_shared<Walk>());
  addState(playerTurn, std::make_shared<Empty>());
  addState(skip, std::make_shared<Empty>());
  addState(endTurn, std::make_shared<Empty>());
  addState(attack, std::make_shared<Attack>());

  addTransition(example, endTurn, NEXT);
  addTransition(tutorial, playerTurn, NEXT);

  addTransition(playerTurn, example, MENU_EXAMPLE);
  addTransition(playerTurn, tutorial, MENU_TUTORIAL);
  addTransition(playerTurn, walk, MENU_WALK);
  addTransition(playerTurn, attack, MENU_ATTACK);
  addTransition(playerTurn, shutdown, MENU_SHUTDOWN);
  addTransition(playerTurn, skip, MENU_SKIP);

  addTransition(startWorld, idleWorld, NEXT);
  addTransition(skip, idleWorld, NEXT);
  addTransition(idleWorld, playerTurn, NEXT);

  // TODO: missing addTransition(attack, endTurn, NEXT);
  // TODO: missing addTransition(walk, endTurn, NEXT);
  addTransition(attack, playerTurn, PREVIOUS);
  addTransition(walk, playerTurn, PREVIOUS);
  addTransition(endTurn, idleWorld, NEXT);

  auto currentMachine = getState(mActiveState);
  currentMachine->triggerTransition(START);
}

void GameEngine::run() {
  entityHandler.updateViewVariables();
  auto currentState = getState(mActiveState);
  currentState->run();

  if (isTerminated()) {
    return;
  }

  if (currentState->activeState() == Substate::TERMINATED) {
    getState(mActiveState)->triggerTransition(RESET);
    loadNextState();
    return;
  } else if (currentState->activeState() == Substate::Cancel) {
    getState(mActiveState)->triggerTransition(RESET);

    triggerTransition(PREVIOUS);
    getState(mActiveState)->triggerTransition(START);
    return;
  }
}

bool GameEngine::isTerminated() {
  auto currentState = getState(mActiveState);
  return (mActiveState == shutdown) && (currentState->activeState() == Substate::TERMINATED);
}

void GameEngine::addState(StateId stateId, std::shared_ptr<StateMachine> state) {
  std::pair<StateId, std::shared_ptr<StateMachine>> entry{stateId, state};
  gameStates.insert(gameStates.begin(), entry);
  stateNetwork.addNode(stateId, "");
}

void GameEngine::loadNextState() {
  mNeighbours = stateNetwork.neighbours(mActiveState);
  if (mNeighbours.size() == 1) {
    automaticTransition();
  } else {
    manualTransition();
  }
}

void GameEngine::automaticTransition() {
  auto transition = stateNetwork.getEdge(LinkId{mActiveState, mNeighbours[0]});
  // Handle change of Macro State
  triggerTransition(transition);
  getState(mActiveState)->triggerTransition(START);
}

void GameEngine::manualTransition() {
  fillOptions();
  handleUserInput();
}

void GameEngine::fillOptions() {
  mOptions = "";
  for (auto neighbour : mNeighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{mActiveState, neighbour});
    mOptions += edgeInfo;

    auto nodeInfo = stateNetwork.getNode(neighbour);
    auto stateName = magic_enum::enum_name(MACRO_STATES{neighbour}).data();
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, stateName);
  }
}

void GameEngine::handleUserInput() {
  mPrinter.addToOptionHeader(Verbose::INFO, "Select menu option ..");
  mPrinter.printScreen();
  auto input = input::readAlphaNum(mOptions);

  // Handle change of Macro State
  triggerTransition(input);
  getState(mActiveState)->triggerTransition(START);
}

std::shared_ptr<StateMachine> GameEngine::getState(const StateId stateId) {
  return gameStates.at(stateId);
}

} // namespace model::state
