//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>

#include "game/controller/event/Example.h"
#include "game/controller/event/GuessWhat.h"
#include "game/controller/event/Tutorial.h"
#include "game/controller/input/Input.h"
#include "game/controller/state/Attack.h"
#include "game/controller/state/Empty.h"
#include "game/controller/state/IdleWorld.h"
#include "game/controller/state/Shutdown.h"
#include "game/controller/state/Start.h"
#include "game/controller/state/UseItem.h"
#include "game/controller/state/Walk.h"
#include "game/controller/state/include/Menu.h"
#include "game/controller/state/include/State.h"
#include "game/controller/state/include/Substate.h"
#include "game/controller/state/include/Transition.h"

namespace controller {

GameEngine::GameEngine() {
  mActiveState = ST_CREATION;

  addState(ST_BATTLE_CHARACTER, std::make_shared<Attack>());
  addState(ST_PLAYER_EVENTS, std::make_shared<Empty>());
  // FIXME: Example is a type of event, not quest
  addState(ST_QUEST_READ, std::make_shared<Example>(false, CRABMODE, 0, -5));
  addState(ST_WORLD_AT_LARGE, std::make_shared<IdleWorld>());
  addState(ST_PLAYER_TURN, std::make_shared<Empty>());
  addState(ST_ITEM_USE, std::make_shared<UseItem>());
  addState(ST_TERMINATE, std::make_shared<Shutdown>());
  addState(ST_SKIP_TURN, std::make_shared<Empty>());
  addState(ST_CREATION, std::make_shared<Start>());
  addState(ST_TUTORIAL, std::make_shared<Tutorial>());
  addState(ST_TRAVEL, std::make_shared<Walk>());

  addTransition(ST_PLAYER_TURN, ST_BATTLE_CHARACTER, TR_BATTLE_CHARACTER);
  addTransition(ST_PLAYER_TURN, ST_ITEM_USE, TR_ITEM_USE);
  addTransition(ST_PLAYER_TURN, ST_QUEST_READ, TR_QUEST_READ);
  addTransition(ST_PLAYER_TURN, ST_TERMINATE, TR_TERMINATE);
  addTransition(ST_PLAYER_TURN, ST_SKIP_TURN, TR_SKIP_TURN);
  addTransition(ST_PLAYER_TURN, ST_TUTORIAL, TR_TUTORIAL);
  addTransition(ST_PLAYER_TURN, ST_TRAVEL, TR_TRAVEL);

  addTransition(ST_ITEM_USE, ST_PLAYER_TURN, PREVIOUS);
  addTransition(ST_BATTLE_CHARACTER, ST_PLAYER_TURN, PREVIOUS);
  addTransition(ST_QUEST_READ, ST_PLAYER_TURN, PREVIOUS);
  addTransition(ST_TRAVEL, ST_PLAYER_TURN, PREVIOUS);

  addTransition(ST_WORLD_AT_LARGE, ST_PLAYER_TURN, NEXT);
  addTransition(ST_TUTORIAL, ST_PLAYER_TURN, NEXT);
  addTransition(ST_PLAYER_EVENTS, ST_WORLD_AT_LARGE, NEXT);
  addTransition(ST_SKIP_TURN, ST_WORLD_AT_LARGE, NEXT);
  addTransition(ST_CREATION, ST_WORLD_AT_LARGE, NEXT);
  addTransition(ST_BATTLE_CHARACTER, ST_PLAYER_EVENTS, NEXT);
  addTransition(ST_QUEST_READ, ST_PLAYER_EVENTS, NEXT);
  addTransition(ST_ITEM_USE, ST_PLAYER_EVENTS, NEXT);
  addTransition(ST_TRAVEL, ST_PLAYER_EVENTS, NEXT);

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
  return (mActiveState == ST_TERMINATE) && (currentState->activeState() == TERMINATED);
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
    std::string stateName = magic_enum::enum_name(State{neighbour}).data();
    // TODO: string clipping should have a centralized library, or should be calculated at compile time
    stateName.replace(0, 3, "");
    std::replace(stateName.begin(), stateName.end(), '_', ' ');
    view::Printer::addToOptions(Verbose::INFO, edgeInfo, stateName);
  }
}

void GameEngine::handleUserInput() {
  view::Printer::addToOptionHeader(Verbose::INFO, "Select menu option ..");
  view::Printer::printScreen();
  auto input = input::readAlphaNum(mOptions);
  triggerTransition(input);
}

} // namespace controller
