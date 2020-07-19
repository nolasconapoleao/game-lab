//
// Created by nolasco on 09/07/20.
//

#pragma once

#include "datatypes/event/CrabDifficulty.h"
#include "datatypes/event/Platform.h"
#include "interface/state-machine/StateMachine.h"
#include "model/handler/Handler.h"
#include "view/Printer.h"
#include "view/entity/StreamConverter.h"

namespace controller {

class KingCrab : public StateMachine {
public:
  KingCrab(bool isMaze, CrabDifficulty difficulty, ResourceId origin, int8_t exitScore);
  void createNetwork();
  void run() final;

protected:
  void fillOptions();
  void handleUserInput();
  virtual void punish() = 0;
  virtual void reward() = 0;
  void restoreState();
  bool isInputCorrect(const char input);
  void openAnswerInput();

  std::vector<Platform> mKingCrab;
  bool mIsMaze;
  StateId previousPlatform;
  std::string mOptions;
  std::string mStringInput;
  Handler mHandler;
  CrabDifficulty mDifficulty;
  ResourceId mOrigin;
  int8_t mAccumulatedScore;
  int8_t mExitScore;
};

} // namespace controller