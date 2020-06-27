//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>
#include <model/state/include/Substate.h>
#include <model/state/include/Transition.h>

#include "input/Input.h"
#include "model/state/Example.h"
#include "model/state/IdleWorld.h"
#include "model/state/Shutdown.h"
#include "model/state/Start.h"
#include "model/state/Travel.h"
#include "model/state/Tutorial.h"

enum MACRO_STATES : StateId {
  example = 0,
  idleWorld,
  shutdown,
  startWorld,
  tutorial,
  walk,
  attack,
  wait,
  playerInput,
};

namespace model::state {
GameEngine::GameEngine() {
  mActiveState = startWorld;

  gameStates.emplace_back(std::make_shared<Example>());
  gameStates.emplace_back(std::make_shared<IdleWorld>());
  gameStates.emplace_back(std::make_shared<Shutdown>());
  gameStates.emplace_back(std::make_shared<Start>());
  gameStates.emplace_back(std::make_shared<Tutorial>());
  gameStates.emplace_back(std::make_shared<Travel>());

  addState(MACRO_STATES::example, "Example");
  addState(MACRO_STATES::idleWorld, "IdleWorld");
  addState(MACRO_STATES::shutdown, "Shutdown");
  addState(MACRO_STATES::startWorld, "Start");
  addState(MACRO_STATES::tutorial, "Tutorial");
  addState(MACRO_STATES::walk, "Walk");

  addTransition(startWorld, idleWorld, 'n');
  addTransition(idleWorld, example, 'e');
  addTransition(idleWorld, walk, 'w');
  addTransition(idleWorld, shutdown, 'x');
  addTransition(walk, idleWorld, 'p');
  addTransition(idleWorld, tutorial, 't');
  addTransition(tutorial, idleWorld, 'n');
  addTransition(example, idleWorld, 'n');
  // TODO: Since this linkId is repeated it refuses to connect the states
  addTransition(example, idleWorld, 'p');

  auto currentMachine = getState(mActiveState);
  currentMachine->triggerTransition(Transitions::START);
}

void GameEngine::run() {
  entityHandler.updateViewVariables();
  auto currentState = getState(mActiveState);
  currentState->run();

  if (isTerminated()) {
    return;
  }

  if (currentState->activeState() == Substate::TERMINATED) {
    getState(mActiveState)->triggerTransition(Transitions::RESET);
    loadAnotherMacroState();
    return;
  } else if (currentState->activeState() == Substate::USER_TERMINATED) {
    getState(mActiveState)->triggerTransition(Transitions::RESET);

    triggerTransition(Transitions::PREVIOUS);
    getState(mActiveState)->triggerTransition(Transitions::START);
    return;
  }
}

bool GameEngine::isTerminated() {
  auto currentState = getState(mActiveState);
  return (mActiveState == shutdown) && (currentState->activeState() == Substate::TERMINATED);
}

void GameEngine::loadAnotherMacroState() {
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
  getState(mActiveState)->triggerTransition(Transitions::START);
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
  getState(mActiveState)->triggerTransition(Transitions::START);
}

std::shared_ptr<StateMachine> GameEngine::getState(const StateId stateId) {
  return gameStates.at(stateId);
}

} // namespace model::state
