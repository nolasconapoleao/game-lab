#include "game/Game.h"

int main() {
  Game game = Game();
  game.initGame();

  while (!game.isGameOver()) {
    game.loop();
  }
  game.closeGame();

  return 0;
}
