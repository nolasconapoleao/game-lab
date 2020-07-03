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
  startWorld = 0,
  idleWorld,
  playerTurn,
  example,
  tutorial,
  attack,
  walk,
  skip,
  endTurn,
  shutdown,
};

namespace model::state {
GameEngine::GameEngine() {
  mActiveState = startWorld;

  addState(attack, std::make_shared<Attack>());
  addState(endTurn, std::make_shared<Empty>());
  addState(example, std::make_shared<Example>());
  addState(idleWorld, std::make_shared<IdleWorld>());
  addState(playerTurn, std::make_shared<Empty>());
  addState(shutdown, std::make_shared<Shutdown>());
  addState(skip, std::make_shared<Empty>());
  addState(startWorld, std::make_shared<Start>());
  addState(tutorial, std::make_shared<Tutorial>());
  addState(walk, std::make_shared<Walk>());

  addTransition(attack, endTurn, NEXT);
  addTransition(endTurn, idleWorld, NEXT);
  addTransition(example, endTurn, NEXT);
  addTransition(idleWorld, playerTurn, NEXT);
  addTransition(skip, idleWorld, NEXT);
  addTransition(startWorld, idleWorld, NEXT);
  addTransition(tutorial, playerTurn, NEXT);
  addTransition(walk, endTurn, NEXT);

  addTransition(playerTurn, attack, MENU_ATTACK);
  addTransition(playerTurn, example, MENU_EXAMPLE);
  addTransition(playerTurn, shutdown, MENU_SHUTDOWN);
  addTransition(playerTurn, skip, MENU_SKIP);
  addTransition(playerTurn, tutorial, MENU_TUTORIAL);
  addTransition(playerTurn, walk, MENU_WALK);

  addTransition(attack, playerTurn, PREVIOUS);
  addTransition(walk, playerTurn, PREVIOUS);

  gameStates[mActiveState]->triggerTransition(START);
}

void GameEngine::run() {
  controller.updateViewVariables();
  gameStates[mActiveState]->run();

  if (isTerminated()) {
    return;
  }

  const auto activeSubstate = gameStates[mActiveState]->activeState();
  if (activeSubstate == TERMINATED || activeSubstate == Cancel) {
    gameStates[mActiveState]->triggerTransition(RESET);

    if (activeSubstate == TERMINATED) {
      if (!triggerTransition(NEXT)) {
        manualTransition();
      }
    } else if (activeSubstate == Cancel) {
      triggerTransition(PREVIOUS);
    }
    gameStates[mActiveState]->triggerTransition(START);
  }
}

bool GameEngine::isTerminated() {
  auto currentState = gameStates[mActiveState];
  return (mActiveState == shutdown) && (currentState->activeState() == TERMINATED);
}

void GameEngine::addState(StateId stateId, std::shared_ptr<StateMachine> state) {
  std::pair<StateId, std::shared_ptr<StateMachine>> entry{stateId, state};
  gameStates.insert(gameStates.begin(), entry);
  stateNetwork.addNode(stateId, magic_enum::enum_name(MACRO_STATES{stateId}).data());
}

void GameEngine::manualTransition() {
  fillOptions();
  handleUserInput();
}

void GameEngine::fillOptions() {
  mOptions = "";
  mNeighbours = stateNetwork.neighbours(mActiveState);
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
  triggerTransition(input);
}

} // namespace model::state
