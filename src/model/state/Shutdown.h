//
// Created by nolasco on 21/06/20.
//

#pragma once

#include "common/GameTypes.h"
#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

class Shutdown : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  Shutdown();
  void whatsUp() override;

protected:
  void continueToNext();

  view::Printer mPrinter;
};

} // namespace model::state
