#include <csignal>

#include "input/Signal_Handler.h"
#include "model/GameEngine.h"

int main() {
  view::Printer printer;
  printer.setVerboseLevel(Verbose::INFO);

  model::state::GameEngine engine;
  signal(SIGINT, Input::signal_callback_handler);

  while (!engine.isTerminated()) {
    engine.run();
  }

  return 0;
}
