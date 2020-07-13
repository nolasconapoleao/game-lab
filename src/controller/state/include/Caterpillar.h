//
// Created by nolasco on 25/06/20.
//

#pragma once

#include "model/handler/Controller.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace controller {

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

  std::vector<StateId> mCaterpillar;
  std::unordered_set<StateId> mNeighbours;
  std::vector<ResourceId> mInput;
  std::vector<ResourceId> mInputParser;
  std::string mOptions;
  Controller mHandler;
};

} // namespace controller
