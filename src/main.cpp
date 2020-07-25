#include <controller/GameEngine.h>
#include <controller/brain-player/input/Signal_Handler.h>
#include <csignal>
#include <model/World.h>
#include <model/cleaner/Cleaner.h>
#include <model/factory/Factory.h>
#include <model/handler/Handler.h>
#include <model/lookup/Lookup.h>
#include <view/Printer.h>

int main() {
  signal(SIGINT, Input::signal_callback_handler);

  // Model classes
  auto world = std::make_shared<model::World>();
  auto lookup = std::make_shared<model::Lookup>(world);
  auto factory = std::make_shared<model::Factory>(world);
  auto cleaner = std::make_shared<model::Cleaner>(world, lookup);
  auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);
  handler->createWorld();

  // View classes
  auto printer = std::make_shared<view::Printer>(lookup);
  printer->printScreen(LogicState::ATTACK);

  // Controller classes
  auto controller = std::make_shared<controller::GameEngine>(handler, lookup);

  while (!controller->isTerminated()) {
    controller->run();
  }

  return 0;
}
