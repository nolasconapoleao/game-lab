#include <csignal>
#include <model/cleaner/Cleaner.h>
#include <model/factory/Factory.h>
#include <model/giga-brain/GigaBrain.h>
#include <model/lookup/Lookup.h>

#include "controller/GameEngine.h"
#include "controller/input/Signal_Handler.h"

// TODO: using namespace model;
// TODO: using namespace view;
// TODO: using namespace controller;

int main() {
  signal(SIGINT, Input::signal_callback_handler);

  // Model classes
  model::World world;
  model::Cleaner cleaner{std::make_shared<model::World>(world)};
  model::Factory factory{std::make_shared<model::World>(world)};
  model::Handler handler{std::make_shared<model::World>(world), std::make_shared<model::Factory>(factory),
                         std::make_shared<model::Cleaner>(cleaner)};
  model::Lookup lookup{std::make_shared<model::World>(world)};
  model::GigaBrain gigaBrain{std::make_shared<model::Handler>(handler), {std::make_shared<model::Lookup>(lookup)}};

  // View classes
  view::Printer::setVerboseLevel(Verbose::INFO);

  // Controller classes
  controller::GameEngine engine;

  while (!engine.isTerminated()) {
    engine.run();
  }

  return 0;
}
