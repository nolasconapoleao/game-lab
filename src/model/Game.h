//
// Created by nolasco on 02/06/20.
//

#pragma once

#include "GameEngine.h"
#include "factory/EntityFactory.h"
#include "view/Printer.h"

namespace model {

class Game {

public:
  Game();
  const bool isOver();
  void loop();
  virtual ~Game();

private:
  void init();
  void shutdown();

  view::Printer mPrinter;
  // FIXME: [nn] Remove this factory class member
  EntityFactory factory;
  model::state::GameEngine gameEngine;
  bool mTerminateGame;
};

} // namespace model
