//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "utils/graph/DirectedGraph.h"
#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

class Tutorial : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  Tutorial();
  void whatsUp();

private:
  std::string name;
  uint8_t attempts;
  std::vector<std::string> failOutput;
  view::Printer mPrinter;
};

} // namespace model::state