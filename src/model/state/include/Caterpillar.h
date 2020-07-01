//
// Created by nolasco on 25/06/20.
//

#pragma once

#include "controller/handler/Controller.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class Caterpillar : public StateMachine {

public:
  void createNetwork();
  void run() final;

protected:
  void fillOptions();
  void handleUserInput();
  virtual void execute() = 0;
  virtual void fillStateOption() = 0;
  void fillBaseOptions();

  bool isTerminated();
  bool isUserTerminated();

  std::vector<StateId> mCaterpillar;
  std::vector<StateId> mNeighbours;
  std::vector<ResourceId> mInput;
  std::vector<ResourceId> mInputParser;
  view::Printer mPrinter;
  std::string mOptions;
  Controller mHandler;
  World mWorld;
};

} // namespace model::state
