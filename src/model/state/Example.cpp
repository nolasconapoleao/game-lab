//
// Created by nolasco on 11/06/20.
//

#include "Example.h"

#include "controller/Controller.h"
#include "controller/Options.h"

enum STATES : StateId {
  ENTER_1 = 1,
  ENTER_2,
  WRONG,
  DONE,
};

namespace model::state {

Example::Example() {
  addState(ENTER_1, "Guess a number");
  addState(ENTER_2, "Guess another number");
  addState(WRONG, "Wrong. Start over");
  addState(DONE, "Very well");

  addTransition(STATE_STANDBYE, ENTER_1, 's');
  addTransition(ENTER_1, ENTER_2, '1');
  addTransition(ENTER_1, WRONG, '2');

  addTransition(ENTER_2, WRONG, '1');
  addTransition(ENTER_2, DONE, '2');

  addTransition(WRONG, ENTER_1, '0');
  addTransition(DONE, STATE_STANDBYE, 'b');
}

void Example::whatsUp() {
  mPrinter.directPrint(stateNetwork.getNode(activeState));
  mNeighbours = stateNetwork.neighbours(activeState);

  if (mNeighbours.size() == 1) {
    continueToNext();
    return;
  }

  fillOptions();
  handleUserInput();
}

void Example::continueToNext() {
  auto transition = stateNetwork.getEdge(LinkId{activeState, mNeighbours[0]});
  triggerTransition(transition);
}

void Example::fillOptions() {
  mOptions = "";
  for (auto neighbour : mNeighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{activeState, neighbour});
    mOptions += edgeInfo;

    auto nodeInfo = stateNetwork.getNode(neighbour);
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, std::string(1, edgeInfo));
  }
  mOptions += controller::backOption;
  mPrinter.addToOptions(Verbose::INFO, controller::backOption, controller::backOptionStr);
}

void Example::handleUserInput() {
  mPrinter.printScreen();
  auto input = controller::readAlphaNum(mOptions);

  if (controller::backOption == input) {
    endState();
    return;
  }

  triggerTransition(input);
}

} // namespace model::state