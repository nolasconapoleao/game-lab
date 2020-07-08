//
// Created by nolasco on 25/06/20.
//

#include "Caterpillar.h"

#include <magic_enum/include/magic_enum.hpp>

#include "Substate.h"
#include "Transition.h"
#include "input/Input.h"

namespace model::state {

void Caterpillar::createNetwork() {
  // FIXME: [nn] this should be simplified
  addState(IDLE, "Macro state is standing bye");
  addState(TERMINATED, "Macro state was terminated");

  if (mCaterpillar.size() != 0) {
    addState(Cancel, "Macro state was terminated by user");
    addTransition(Cancel, IDLE, RESET);
  }

  mCaterpillar.emplace_back(EXECUTE);
  for (const auto stateId : mCaterpillar) {
    addState(stateId, magic_enum::enum_name(Substate{stateId}).data());
  }

  addTransition(IDLE, mCaterpillar.at(0), START);
  for (auto it = 0; it < mCaterpillar.size() - 1; it++) {
    if (mCaterpillar.at(it) != EXECUTE) {
      addTransition(mCaterpillar.at(it), mCaterpillar.at(it + 1), NEXT);
      addTransition(mCaterpillar.at(it + 1), mCaterpillar.at(it), PREVIOUS);
      addTransition(mCaterpillar.at(it), Cancel, CANCEL);
    }
  }
  addTransition(EXECUTE, TERMINATED, NEXT);
  addTransition(TERMINATED, IDLE, RESET);

  mInput.reserve(mCaterpillar.size());
  mActiveState = IDLE;
}

void Caterpillar::run() {
  if (mActiveState == EXECUTE) {
    execute();
  } else {
    fillOptions();
    handleUserInput();
  }

  triggerTransition(NEXT);
}

void Caterpillar::fillOptions() {
  mOptions = "";
  fillStateOption();
  fillBaseOptions();
}

void Caterpillar::fillBaseOptions() {
  mNeighbours = stateNetwork.neighbours(mActiveState);
  for (const auto neighbour : mNeighbours) {
    auto edgeInfo = stateNetwork.getEdge(LinkId{mActiveState, neighbour});
    if (edgeInfo != NEXT) {
      mOptions += edgeInfo;
      Transitions transition = Transitions{edgeInfo};
      mPrinter.addToOptions(Verbose::INFO, edgeInfo, magic_enum::enum_name(transition).data());
    }
  }
}

void Caterpillar::handleUserInput() {
  mPrinter.printScreen();
  auto input = input::readAlphaNum(mOptions);
  if (CANCEL == input || PREVIOUS == input || NEXT == input) {
    triggerTransition(input);
  } else {
    mInput[mActiveState] = input - '0';
  }
}

} // namespace model::state