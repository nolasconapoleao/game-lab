//
// Created by nolasco on 24/06/20.
//

#pragma once

#include "controller/handler/EntityHandler.h"
#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

class Travel : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  Travel();
  void whatsUp() override;

private:
  void continueToNext();
  void fillOptions();
  void handleUserInput();
  void fillStateOption();

  view::Printer mPrinter;
  std::vector<StateId> mNeighbours;
  std::string mOptions;
  EntityHandler mHandler;
};

} // namespace model::state
