//
// Created by nolasco on 10/06/20.
//

#pragma once

#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class GameEngine : StateMachine {
public:
  using LinkId = StateMachine::LinkId;

  GameEngine();
  void whatsUp() override;

private:
  view::Printer mPrinter;
};

} // namespace model::state
