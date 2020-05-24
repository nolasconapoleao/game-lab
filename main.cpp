#include "game/Renderer.h"

int main() {
  Renderer game = Renderer();
  game.initGame();

  while (!game.isGameOver()) {
    game.loop();
  }
  game.closeGame();

  return 0;
}
