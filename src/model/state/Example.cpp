//
// Created by nolasco on 11/06/20.
//

#include "Example.h"

#include "input/Input.h"
#include "model/state/include/Substate.h"
#include "model/state/include/Transition.h"

enum STATES : StateId {
  ENTER_1 = 1,
  ENTER_2,
  WRONG,
};

namespace model::state {

Example::Example() {
  addState(IDLE, "Macro state is in stand bye");
  addState(ENTER_1, "Guess a number");
  addState(ENTER_2, "Guess another number");
  addState(WRONG, "Wrong. Start over");
  addState(TERMINATED, "Very well");
  addState(USER_TERMINATED, "Macro state was terminated by you");

  addTransition(IDLE, ENTER_1, 's');
  addTransition(ENTER_1, ENTER_2, '1');
  addTransition(ENTER_1, WRONG, '2');

  addTransition(ENTER_2, WRONG, '1');
  addTransition(ENTER_2, TERMINATED, '2');

  addTransition(WRONG, ENTER_1, ' ');
  addTransition(TERMINATED, IDLE, 'r');
  addTransition(USER_TERMINATED, IDLE, 'r');
  mActiveState = IDLE;
}

void Example::run() {
  mPrinter.directPrint(stateNetwork.getNode(mActiveState));
  mNeighbours = stateNetwork.neighbours(mActiveState);

  if (mNeighbours.size() == 1) {
    continueToNext();
    return;
  }

  fillOptions();
  handleUserInput();
}

void Example::continueToNext() {
  auto transition = stateNetwork.getEdge(LinkId{mActiveState, mNeighbours[0]});
  triggerTransition(transition);
}

void Example::fillOptions() {
  mOptions = "";
  for (auto neighbour : mNeighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{mActiveState, neighbour});
    mOptions += edgeInfo;

    auto nodeInfo = stateNetwork.getNode(neighbour);
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, std::string(1, edgeInfo));
  }
  mOptions += Transitions::CANCEL;
  mPrinter.addToOptions(Verbose::INFO, Transitions::CANCEL, "back");
}

void Example::handleUserInput() {
  mPrinter.printScreen();
  auto input = input::readAlphaNum(mOptions);

  if (Transitions::CANCEL == input) {
    mActiveState = USER_TERMINATED;
    return;
  }

  triggerTransition(input);
}

} // namespace model::state
