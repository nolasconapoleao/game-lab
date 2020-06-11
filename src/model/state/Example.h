//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

class Example : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  Example();
  void whatsUp() override;

protected:
  void continueToNext();
  void fillOptions();
  void handleUserInput();

  view::Printer mPrinter;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
};

} // namespace model::state
