//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>

#include "controller/Controller.h"
#include "controller/Options.h"
#include "model/state/Example.h"
#include "model/state/RunWorld.h"
#include "model/state/Tutorial.h"

enum MACRO_STATES : MacroStateId {
  terminate = 0,
  tutorial,
  example,
  attack,
  runWorld,
  playerInput,
  wait,
};

namespace model::state {
GameEngine::GameEngine() {
  activeMacroState = runWorld;

  addMacroState(tutorial, std::make_shared<Tutorial>());
  addMacroState(example, std::make_shared<Example>());
  addMacroState(runWorld, std::make_shared<RunWorld>());

  addTransition(runWorld, example, 'e');
  addTransition(runWorld, tutorial, 't');
  addTransition(tutorial, runWorld, 'c');
  addTransition(example, runWorld, 'c');

  std::shared_ptr<MacroState> currentMachine = macroStateNetwork.getNode(activeMacroState);
  currentMachine->startState();
}

void GameEngine::whatsUp() {
  std::shared_ptr<MacroState> currentMachine = macroStateNetwork.getNode(activeMacroState);
  currentMachine->whatsUp();

  if (!currentMachine->isStandingBye()) {
    return;
  }

  mNeighbours = macroStateNetwork.neighbours(activeMacroState);

  if (mNeighbours.size() == 1) {
    continueToNext();
    return;
  }

  fillOptions();
  handleUserInput();
}

void GameEngine::continueToNext() {
  auto transition = macroStateNetwork.getEdge(LinkId{activeMacroState, mNeighbours[0]});
  triggerTransition(transition);

  startNextMacroState();
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
  mOptions += controller::closeOption;
  mPrinter.addToOptions(Verbose::INFO, controller::closeOption, controller::closeOptionStr);
}

void GameEngine::handleUserInput() {
  // TODO: [nn] Add option header
  mPrinter.addToHud(Verbose::INFO, "Select menu option ..");
  mPrinter.printScreen();
  auto input = controller::readAlphaNum(mOptions);
  triggerTransition(input);

  startNextMacroState();

  if (controller::closeOption == input) {
    activeMacroState = TERMINATE;
    return;
  }
  triggerTransition(input);
}

bool GameEngine::isTerminated() {
  return activeMacroState == TERMINATE;
}

void GameEngine::startNextMacroState() {
  std::shared_ptr<MacroState> newMachine = macroStateNetwork.getNode(activeMacroState);
  newMachine->startState();
}

} // namespace model::state
