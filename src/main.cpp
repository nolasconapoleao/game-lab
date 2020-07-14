#include <csignal>

#include "game/controller/GameEngine.h"
#include "game/controller/input/Signal_Handler.h"

int main() {
  view::Printer::setVerboseLevel(Verbose::INFO);

  controller::GameEngine engine;
  signal(SIGINT, Input::signal_callback_handler);

  while (!engine.isTerminated()) {
    engine.run();
  }

  return 0;
}
