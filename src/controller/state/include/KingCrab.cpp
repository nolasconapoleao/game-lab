//
// Created by nolasco on 09/07/20.
//

#include "KingCrab.h"

#include <magic_enum/include/magic_enum.hpp>

#include "Substate.h"
#include "Transition.h"
#include "input/Input.h"

namespace controller {

constexpr StateId START_STATE_ID = 50;
KingCrab::KingCrab(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer)
    : mIsMaze(isMaze), mDifficulty(difficulty), mEventOriginer(eventOriginer) {
}

void KingCrab::createNetwork() {
  addState(IDLE, "Macro state is standing bye");
  addState(TERMINATED, "Macro state was terminated");
  addState(PUNISH, "Incorrect answer was received");
  addState(REWARD, "Event finished successfully");

  if (!mIsMaze) {
    addState(Cancel, "Macro state was terminated by user");
    addTransition(Cancel, IDLE, RESET);
  }

  for (auto it = 0; it < mKingCrab.size(); it++) {
    StateId stateId = START_STATE_ID + it;
    addState(stateId, mKingCrab[it].OptionHeader);
  }

  for (auto it = 0; it < mKingCrab.size(); it++) {
    StateId stateId = START_STATE_ID + it;
    (it < (mKingCrab.size() - 1)) ? addTransition(stateId, stateId + 1, CORRECT)
                                  : addTransition(stateId, REWARD, CORRECT);

    if (!mIsMaze) {
      addTransition(stateId, Cancel, CANCEL);
    }
    addTransition(stateId, PUNISH, INCORRECT);
    addTransition(PUNISH, stateId, '0' + it + START_STATE_ID);
  }

  addTransition(IDLE, START_STATE_ID, START);
  addTransition(TERMINATED, IDLE, RESET);
  addTransition(REWARD, TERMINATED, NEXT);
  addTransition(PUNISH, TERMINATED, TERMINATE);
  addTransition(PUNISH, REWARD, FORGIVEN);
  mActiveState = IDLE;
}

void KingCrab::run() {
  if (mActiveState == PUNISH) {
    // TODO: eventOnwer will scold you for failing
    view::Printer::addToRoundReport(Verbose::INFO, "That is the wrond answer");
    punish();
    restoreState();
  } else if (mActiveState == REWARD) {
    reward();
    triggerTransition(NEXT);
  } else {
    fillOptions();
    handleUserInput();
  }
}

void KingCrab::fillOptions() {
  // TODO: options should be printed in random order
  mOptions = "";
  view::Printer::addToOptionHeader(Verbose::INFO, mKingCrab[mActiveState - START_STATE_ID].OptionHeader);
  for (auto it = 0; it < mKingCrab[mActiveState - START_STATE_ID].alternatives.size(); it++) {
    const auto optionLabel = '0' + it;
    mOptions += optionLabel;
    view::Printer::addToOptions(Verbose::INFO, optionLabel,
                                mKingCrab[mActiveState - START_STATE_ID].alternatives[it].first);
  }

  if (!mIsMaze) {
    view::Printer::addToOptions(Verbose::INFO, CANCEL, magic_enum::enum_name(Cancel).data());
    mOptions += CANCEL;
  }
}

void KingCrab::handleUserInput() {
  view::Printer::printScreen();
  auto input = input::readAlphaNum(mOptions);
  if (CANCEL == input) {
    triggerTransition(input);
  } else {
    if (isInputCorrect(input)) {
      triggerTransition(CORRECT);
    } else {
      previousPlatform = mActiveState;
      triggerTransition(INCORRECT);
    }
  }
}

void KingCrab::restoreState() {
  switch (mDifficulty) {
    case CRABMODE:
      triggerTransition('0' + previousPlatform);
      break;
    case UNFORGIVING:
      triggerTransition('0' + START_STATE_ID);
      break;
  }
}

bool KingCrab::isInputCorrect(char input) {
  return (mKingCrab[mActiveState - START_STATE_ID].alternatives[input - '0'].second > 0);
}

} // namespace controller