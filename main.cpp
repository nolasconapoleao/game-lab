#include <iostream>

#include "model/Game.h"

int main() {

  model::Game game;

  while(!game.isOver()) {
    game.loop();
  }

  return 0;
}
