#include <csignal>

#include "input/Signal_Handler.h"
#include "model/GameEngine.h"

int main() {
  model::state::GameEngine engine;
  signal(SIGINT, Input::signal_callback_handler);

  while (!engine.engineIsTerminated()) {
    engine.whatsUp();
  }

  return 0;
}
