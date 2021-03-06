#include <csignal>

#include "controller/GameEngine.h"
#include "input/capture/SignalHandler.h"
#include "model/World.h"
#include "model/cleaner/Cleaner.h"
#include "model/factory/Factory.h"
#include "model/handler/Handler.h"
#include "model/lookup/Lookup.h"
#include "utils/exception/ExceptionHandler.h"
#include "view/Printer.h"

int main() {
  // TODO(nn): Print stack trace for exception
  signal(SIGINT, input::signal_callback_handler);
  signal(SIGSEGV, segmentation_handler);

  // Model classes
  auto world = std::make_shared<model::World>();
  auto lookup = std::make_shared<model::Lookup>(world);
  auto factory = std::make_shared<model::Factory>(world);
  auto cleaner = std::make_shared<model::Cleaner>(world, lookup);
  auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

  // Controller classes
  auto controller = std::make_shared<controller::GameEngine>(handler, lookup);

  view::printer::clearScreen();
  while (!controller->isTerminated()) {
    try {
      controller->run();
    } catch (const std::exception &e) {
      std::cerr << e.what();
      return 1;
    }
  }

  return 0;
}
