//
// Created by nolasco on 11/06/20.
//

#include "Example.h"

#include "controller/Controller.h"

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

  addTransition(ENTER_2, DONE, '2');
  addTransition(ENTER_2, WRONG, '1');

  addTransition(WRONG, ENTER_1, '0');

  addTransition(WRONG, STATE_STANDBYE, 'b');
  addTransition(ENTER_1, STATE_STANDBYE, 'b');

  addTransition(DONE, STATE_STANDBYE, 'b');
}

void Example::whatsUp() {
  mPrinter.directPrint(stateNetwork.getNode(activeState));
  auto neighbours = stateNetwork.neighbours(activeState);

  std::string options = "";
  for (auto neighbour : neighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{activeState, neighbour});
    options += edgeInfo;

    auto nodeInfo = stateNetwork.getNode(neighbour);

    mPrinter.addToOptions(Verbose::INFO, edgeInfo, std::string(1, edgeInfo));
  }

  mPrinter.printScreen();
  auto input = controller::readAlphaNum(options);
  triggerTransition(input);
}

void Example::start() {
  triggerTransition('s');
}

} // namespace model::state