//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include <magic_enum/include/magic_enum.hpp>

#include "controller/Controller.h"
#include "model/state/Example.h"
#include "model/state/Tutorial.h"

enum MACRO_STATES : MacroStateId {
  tutorial = 1,
  example,
};

namespace model::state {
GameEngine::GameEngine() {
  activeMacroState = tutorial;

  addMacroState(tutorial, std::make_shared<Tutorial>());
  addMacroState(example, std::make_shared<Example>());

  addTransition(tutorial, example, 'e');
  addTransition(example, tutorial, 't');

  std::shared_ptr<MacroState> currentMachine = macroStateNetwork.getNode(activeMacroState);
  currentMachine->start();
}

void GameEngine::whatsUp() {
  std::shared_ptr<MacroState> currentMachine = macroStateNetwork.getNode(activeMacroState);
  currentMachine->whatsUp();

  if (!currentMachine->isStandingBye()) {
    return;
  }

  auto neighbours = macroStateNetwork.neighbours(activeMacroState);

  std::string options = "";
  for (auto neighbour : neighbours) {
    auto edgeInfo = macroStateNetwork.getEdge(LinkId{activeMacroState, neighbour});
    options += edgeInfo;

    auto nodeInfo = macroStateNetwork.getNode(neighbour);
    auto stateName = magic_enum::enum_name(MACRO_STATES{neighbour}).data();
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, stateName);
  }
  // TODO: [nn] Add option header
  mPrinter.addToHud(Verbose::INFO, "Select option ..");
  mPrinter.printScreen();
  auto input = controller::readAlphaNum(options);
  triggerTransition(input);

  std::shared_ptr<MacroState> newMachine = macroStateNetwork.getNode(activeMacroState);
  newMachine->start();
}

} // namespace model::state
