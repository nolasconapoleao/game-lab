//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "game/model/handler/Handler.h"
#include "game/view/Printer.h"
#include "graph/DirectedGraph.h"
#include "state-machine/StateMachine.h"

namespace controller {

// TODO: tutorial should inherit from kingcrab
class Tutorial : public StateMachine {
  using LinkId = StateMachine::LinkId;

public:
  Tutorial();
  void run();

private:
  std::string name;
  uint8_t attempts;
  std::vector<std::string> failOutput;
  Handler mHandler;
};

} // namespace controller