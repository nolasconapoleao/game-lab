//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>
#include <model/state/StartWorld.h>

#include "input/Input.h"
#include "input/Options.h"
#include "model/state/Example.h"
#include "model/state/IdleWorld.h"
#include "model/state/Tutorial.h"

enum MACRO_STATES : MacroStateId {
  terminate = 0,
  tutorial,
  example,
  attack,
  idleWorld,
  startWorld,
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

  addTransition(startWorld, idleWorld, 's');
  addTransition(idleWorld, example, 'e');
  addTransition(idleWorld, tutorial, 't');
  addTransition(tutorial, idleWorld, 'c');
  addTransition(example, idleWorld, 'c');

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
  mOptions += input::closeOption;
  mPrinter.addToOptions(Verbose::INFO, input::closeOption, input::closeOptionStr);
}

void GameEngine::handleUserInput() {
  // TODO: [nn] Add option header
  mPrinter.addToHud(Verbose::INFO, "Select menu option ..");
  mPrinter.printScreen();
  auto input = input::readAlphaNum(mOptions);
  triggerTransition(input);

  startNextMacroState();

  if (input::closeOption == input) {
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
