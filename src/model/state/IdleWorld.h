//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "common/GameTypes.h"
#include "model/World.h"
#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

class IdleWorld : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  IdleWorld();
  void whatsUp() override;

protected:
  void continueToNext();

  view::Printer mPrinter;
  World mWorld;
};

} // namespace model::state
