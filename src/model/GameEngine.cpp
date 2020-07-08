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
#include "model/state/UseItem.h"
#include "model/state/Walk.h"
#include "model/state/include/Menu.h"
#include "model/state/include/State.h"
#include "model/state/include/Substate.h"
#include "model/state/include/Transition.h"

namespace model::state {

GameEngine::GameEngine() {
  mActiveState = startWorld;

  addState(attack, std::make_shared<Attack>());
  addState(endTurn, std::make_shared<Empty>());
  addState(example, std::make_shared<Example>());
  addState(idleWorld, std::make_shared<IdleWorld>());
  addState(playerTurn, std::make_shared<Empty>());
  addState(useItem, std::make_shared<UseItem>());
  addState(shutdown, std::make_shared<Shutdown>());
  addState(skip, std::make_shared<Empty>());
  addState(startWorld, std::make_shared<Start>());
  addState(tutorial, std::make_shared<Tutorial>());
  addState(walk, std::make_shared<Walk>());

  addTransition(playerTurn, attack, TR_BATTLE_CHARACTER);
  addTransition(playerTurn, useItem, TR_ITEM_USE);
  addTransition(playerTurn, example, TR_QUEST_READ);
  addTransition(playerTurn, shutdown, TR_TERMINATE);
  addTransition(playerTurn, skip, TR_SKIP_TURN);
  addTransition(playerTurn, tutorial, TR_TUTORIAL);
  addTransition(playerTurn, walk, TR_TRAVEL);

  addTransition(useItem, playerTurn, PREVIOUS);
  addTransition(attack, playerTurn, PREVIOUS);
  addTransition(walk, playerTurn, PREVIOUS);

  addTransition(idleWorld, playerTurn, NEXT);
  addTransition(tutorial, playerTurn, NEXT);
  addTransition(endTurn, idleWorld, NEXT);
  addTransition(skip, idleWorld, NEXT);
  addTransition(startWorld, idleWorld, NEXT);
  addTransition(attack, endTurn, NEXT);
  addTransition(example, endTurn, NEXT);
  addTransition(useItem, endTurn, NEXT);
  addTransition(walk, endTurn, NEXT);

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
        fillOptions();
        handleUserInput();
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
  stateNetwork.addNode(stateId, magic_enum::enum_name(State{stateId}).data());
}

void GameEngine::fillOptions() {
  mOptions = "";

  const auto aux = stateNetwork.neighbours(mActiveState);
  mNeighbours.clear();
  std::copy(aux.begin(), aux.end(), std::inserter(mNeighbours, mNeighbours.begin()));

  for (auto neighbour : mNeighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{mActiveState, neighbour});
    mOptions += edgeInfo;

    auto nodeInfo = stateNetwork.getNode(neighbour);
    auto stateName = magic_enum::enum_name(State{neighbour}).data();
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
