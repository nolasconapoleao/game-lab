//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "controller/handler/Controller.h"
#include "utils/graph/DirectedGraph.h"
#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace controller {

// FIX: Define Splitter state for these
class Tutorial : public StateMachine {
  using LinkId = StateMachine::LinkId;

public:
  Tutorial();
  void run();

private:
  std::string name;
  uint8_t attempts;
  std::vector<std::string> failOutput;
  Controller mHandler;
};

} // namespace controller