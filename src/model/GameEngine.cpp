//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>
#include <model/state/Shutdown.h>
#include <model/state/StartWorld.h>

#include "input/Input.h"
#include "input/Options.h"
#include "model/state/Example.h"
#include "model/state/IdleWorld.h"
#include "model/state/Tutorial.h"

enum MACRO_STATES : MacroStateId {
  tutorial = 0,
  example,
  attack,
  idleWorld,
  startWorld,
  shutdown,
  playerInput,
  wait,
};

namespace model::state {
GameEngine::GameEngine() {
  activeMacroState = startWorld;

  addMacroState(startWorld, std::make_shared<StartWorld>());
  addMacroState(tutorial, std::make_shared<Tutorial>());
  addMacroState(example, std::make_shared<Example>());
  addMacroState(idleWorld, std::make_shared<IdleWorld>());
  addMacroState(shutdown, std::make_shared<Shutdown>());

  addTransition(startWorld, idleWorld, ' ');
  addTransition(idleWorld, example, 'e');
  addTransition(idleWorld, tutorial, 't');
  addTransition(tutorial, idleWorld, ' ');
  addTransition(example, idleWorld, ' ');

  std::shared_ptr<MacroState> currentMachine = macroStateNetwork.getNode(activeMacroState);
  currentMachine->startState();
}

void GameEngine::whatsUp() {
  auto currentState = getMacroState(activeMacroState);
  currentState->whatsUp();

  if (!isTerminated() && currentState->isStandingBye()) {
    loadAnotherMacroState();
  }
}

bool GameEngine::isTerminated() {
  auto currentMachine = getMacroState(activeMacroState);
  return (activeMacroState == shutdown) && (currentMachine->isStandingBye());
}

void GameEngine::loadAnotherMacroState() {
  mNeighbours = macroStateNetwork.neighbours(activeMacroState);
  if (mNeighbours.size() == 1) {
    automaticTransition();
  } else {
    manualTransition();
  }
}

void GameEngine::automaticTransition() {
  auto transition = macroStateNetwork.getEdge(LinkId{activeMacroState, mNeighbours[0]});
  // Handle change of Macro State
  triggerTransition(transition);
  getMacroState(activeMacroState)->startState();
}

void GameEngine::manualTransition() {
  fillOptions();
  handleUserInput();
}

void GameEngine::fillOptions() {
  mOptions = "";
  for (auto neighbour : mNeighbours) {
    auto edgeInfo = macroStateNetwork.getEdge(LinkId{activeMacroState, neighbour});
    mOptions += edgeInfo;

    auto nodeInfo = macroStateNetwork.getNode(neighbour);
    auto stateName = magic_enum::enum_name(MACRO_STATES{neighbour}).data();
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, stateName);
  }
  mOptions += input::closeOption;
  mPrinter.addToOptions(Verbose::INFO, input::closeOption, input::closeOptionStr);
}

void GameEngine::handleUserInput() {
  mPrinter.addToOptionHeader(Verbose::INFO, "Select menu option ..");
  mPrinter.printScreen();
  auto input = input::readAlphaNum(mOptions);

  // Handle change of Macro State
  triggerTransition(input);
  getMacroState(activeMacroState)->startState();

  if (input::closeOption == input) {
    activeMacroState = shutdown;
    getMacroState(activeMacroState)->startState();
    return;
  }
  triggerTransition(input);
}

std::shared_ptr<MacroState> GameEngine::getMacroState(const MacroStateId macroStateId) {
  return macroStateNetwork.getNode(macroStateId);
}

} // namespace model::state
