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
  void start() override;
  void whatsUp() override;

protected:
  view::Printer mPrinter;
};

} // namespace model::state
