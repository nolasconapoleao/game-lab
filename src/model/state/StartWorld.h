//
// Created by nolasco on 11/06/20.
//

#pragma once

#include <model/factory/EntityFactory.h>

#include "common/GameTypes.h"
#include "model/World.h"
#include "utils/state-machine/MacroState.h"
#include "view/Printer.h"

namespace model::state {

class StartWorld : public MacroState {
  using LinkId = typename MacroState::LinkId;

public:
  StartWorld();
  void whatsUp() override;

protected:
  void continueToNext();

  view::Printer mPrinter;
  EntityFactory factory;
};

} // namespace model::state
