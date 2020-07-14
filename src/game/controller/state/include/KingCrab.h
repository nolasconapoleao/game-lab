//
// Created by nolasco on 09/07/20.
//

#pragma once

#include "CrabDifficulty.h"
#include "Platform.h"
#include "game/model/handler/Controller.h"
#include "game/view/Printer.h"
#include "state-machine/StateMachine.h"

namespace controller {

class KingCrab : public StateMachine {
public:
  KingCrab(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer, int8_t exitScore);
  void createNetwork();
  void run() final;

protected:
  void fillOptions();
  void handleUserInput();
  virtual void punish() = 0;
  virtual void reward() = 0;
  void restoreState();
  bool isInputCorrect(const char input);

  std::vector<Platform> mKingCrab;
  bool mIsMaze;
  StateId previousPlatform;
  std::string mOptions;
  Controller mHandler;
  CrabDifficulty mDifficulty;
  ResourceId mEventOriginer;
  int8_t mAccumulatedScore;
  int8_t mExitScore;
};

} // namespace controller