//
// Created by nolasco on 09/07/20.
//

#pragma once

#include "CrabDifficulty.h"
#include "Platform.h"
#include "controller/handler/Controller.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace controller {

class KingCrab : public StateMachine {
public:
  KingCrab(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer);
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
};

} // namespace controller