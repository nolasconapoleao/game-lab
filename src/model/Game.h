//
// Created by nolasco on 02/06/20.
//

#include "view/Printer.h"

#pragma once

namespace model {

class Game {

public:
  Game();
  const bool isOver();
  void loop();

private:
  void init();

  view::Printer mPrinter;
  bool mTerminateGame;
};

} // namespace model
