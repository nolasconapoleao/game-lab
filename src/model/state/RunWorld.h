//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "common/GameTypes.h"
#include "model/World.h"
#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

// TODO: Rename to IdleWorld
class RunWorld : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  RunWorld();
  void whatsUp() override;

protected:
  void continueToNext();

  view::Printer mPrinter;
  World mWorld;
};

} // namespace model::state
