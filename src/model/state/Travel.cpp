//
// Created by nolasco on 24/06/20.
//

#include "Travel.h"

#include "input/Input.h"
#include "input/Options.h"

enum STATES : StateId {
  SELECT_DESTINATION = 1,
  EXECUTION,
};

namespace model::state {

Travel::Travel() {
  addState(SELECT_DESTINATION, "Select location");

  addTransition(STATE_STANDBYE, SELECT_DESTINATION, 's');
  addTransition(SELECT_DESTINATION, EXECUTION, ' ');
  addTransition(EXECUTION, STATE_STANDBYE, ' ');
}

void Travel::whatsUp() {
  mPrinter.addToOptionHeader(Verbose::INFO, stateNetwork.getNode(activeState));
  mNeighbours = stateNetwork.neighbours(activeState);

  if (mNeighbours.size() == 1) {
    continueToNext();
    return;
  }

  fillOptions();
  handleUserInput();
}

void Travel::continueToNext() {
  auto transition = stateNetwork.getEdge(LinkId{activeState, mNeighbours[0]});
  triggerTransition(transition);
}

void Travel::fillOptions() {
  mOptions = "";
  for (auto neighbour : mNeighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{activeState, neighbour});
    mOptions += edgeInfo;

    auto nodeInfo = stateNetwork.getNode(neighbour);
    mPrinter.addToOptions(Verbose::INFO, edgeInfo, std::string(1, edgeInfo));
  }
  fillStateOption();
  mOptions += input::backOption;
  mPrinter.addToOptions(Verbose::INFO, input::backOption, input::backOptionStr);
}

void Travel::handleUserInput() {
  mPrinter.printScreen();
  auto input = input::readAlphaNum(mOptions);

  if (input::backOption == input) {
    endState();
    return;
  }

  triggerTransition(input);
}

void Travel::fillStateOption() {
}

} // namespace model::state
