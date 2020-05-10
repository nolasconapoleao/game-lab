#include <iostream>
#include <memory>

#include "src/game/Game.h"

int main() {
  Game game = Game();

  while (!game.isOver()) {
    game.loop();
  }

  return 0;
}
