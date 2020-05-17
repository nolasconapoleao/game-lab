#include <iostream>
#include <memory>

#include "game/Game.h"

int main() {
  Game game = Game();
  game.initGame();

  do {
    game.loop();
  } while (!game.isOver());

  return 0;
}
