//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "utils/state-machine/StateMachine.h"
#include "view/Printer.h"

namespace model::state {

class Example : public StateMachine {
  using LinkId = typename StateMachine::LinkId;

public:
  Example();
  void run() override;

protected:
  void continueToNext();
  void fillOptions();
  void handleUserInput();

  view::Printer mPrinter;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
};

} // namespace model::state
