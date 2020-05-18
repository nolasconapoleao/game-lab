#include "game/Game.h"

int main() {
  Game game = Game();
  game.initGame();

  do {
    game.loop();
  } while (!game.isGameOver());

  return 0;
}
