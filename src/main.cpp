#include <csignal>

#include "model/Game.h"

void signal_callback_handler(int signum) {
  std::cout << std::endl << "AH ye killed me you bastard! Caught signal: " << signum << std::endl;
  exit(signum);
}

int main() {

  signal(SIGINT, signal_callback_handler);
  model::Game game;

  while (!game.isOver()) {
    game.loop();
  }

  return 0;
}
