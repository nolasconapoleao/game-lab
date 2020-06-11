//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include "controller/Controller.h"
#include "model/state/Example.h"
#include "model/state/Tutorial.h"

enum MACRO_STATES : MacroStateId {
  TUTORIAL = 1,
  EXAMPLE,
};

namespace model::state {
GameEngine::GameEngine() {
  activeMacroState = TUTORIAL;

  addMacroState(TUTORIAL, std::make_shared<Tutorial>());
  addMacroState(EXAMPLE, std::make_shared<Example>());

  addTransition(TUTORIAL, EXAMPLE, 'e');
  addTransition(EXAMPLE, TUTORIAL, 't');

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
    // TODO: [nn] magic enum for neighbour
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, "neighbour");
  }
  mPrinter.addToHud(Verbose::INFO, "Select option ..");
  mPrinter.printScreen();
  auto input = controller::readAlphaNum(options);
  triggerTransition(input);

  std::shared_ptr<MacroState> newMachine = macroStateNetwork.getNode(activeMacroState);
  newMachine->start();
}

} // namespace model::state
