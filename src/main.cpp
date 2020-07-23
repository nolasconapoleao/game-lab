#include <csignal>
#include <model/World.h>
#include <model/cleaner/Cleaner.h>
#include <model/factory/Factory.h>
#include <model/giga-brain/GigaBrain.h>
#include <model/lookup/Lookup.h>

#include "view/input/Signal_Handler.h"

//#include "controller/GameEngine.h"

// TODO: using namespace model;
// TODO: using namespace view;
// TODO: using namespace controller;

int main() {
  signal(SIGINT, Input::signal_callback_handler);

  // Model classes
  auto world = std::make_shared<model::World>();
  auto lookup = std::make_shared<model::Lookup>(world);
  auto factory = std::make_shared<model::Factory>(world);
  auto cleaner = std::make_shared<model::Cleaner>(world, lookup);
  auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);
  auto gigaBrain = std::make_shared<model::GigaBrain>(handler, lookup);
  handler->createWorld();

  // View classes
  //  view::Printer::setVerboseLevel(Verbose::INFO);

  // Controller classes
  //  controller::GameEngine engine;

  //  while (!engine.isTerminated()) {
  //    engine.run();
  //  }

  return 0;
}
