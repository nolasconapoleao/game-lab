#include <iostream>

#include "model/Game.h"

int main() {

  // TODO: Game class is a wrapper for GameEngine, remove if possible
  model::Game game;

  while(!game.isOver()) {
    game.loop();
  }

  return 0;
}
