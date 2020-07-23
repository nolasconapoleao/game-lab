//
// Created by nolasco on 25/06/20.
//

#pragma once

#include "interface/state-machine/StateMachine.h"
#include "model/handler/Handler.h"
#include "view/Printer.h"
#include "view/entity/Converter.h"

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
  // FIXME: mInputParser should be used to get the id after getting input
  std::vector<ResourceId> mInputParser;
  std::string mOptions;
  Handler mHandler;
};

} // namespace controller
