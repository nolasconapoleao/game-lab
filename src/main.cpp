#include <csignal>
#include <model/cleaner/Cleaner.h>
#include <model/factory/Factory.h>
#include <model/giga-brain/GigaBrain.h>
#include <model/lookup/Lookup.h>

#include "controller/GameEngine.h"
#include "controller/input/Signal_Handler.h"

int main() {
  signal(SIGINT, Input::signal_callback_handler);

  model::World world;
  model::Cleaner cleaner;
  model::Factory factory;
  model::Handler handler;
  model::Lookup lookup;
  model::GigaBrain gigaBrain;

  view::Printer::setVerboseLevel(Verbose::INFO);

  controller::GameEngine engine;

  while (!engine.isTerminated()) {
    engine.run();
  }

  return 0;
}
