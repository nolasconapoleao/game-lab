//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "controller/GameEngine.h"
#include "model/World.h"
#include "model/cleaner/Cleaner.h"
#include "model/factory/Factory.h"
#include "model/handler/Handler.h"
#include "model/lookup/Lookup.h"

SCENARIO("Full game validation", "[Lookup]") {

  GIVEN("The multiple game objects") {
    // Model classes
    auto world = std::make_shared<model::World>();
    auto lookup = std::make_shared<model::Lookup>(world);
    auto factory = std::make_shared<model::Factory>(world);
    auto cleaner = std::make_shared<model::Cleaner>(world, lookup);
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    // Controller classes
    auto controller = std::make_shared<controller::GameEngine>(handler, lookup);

    // TODO: Mock call for player input
    //    WHEN("The game cycle is run") {
    //      CHECK_NOTHROW(controller->run());
    //      THEN("No exception is thrown") {
    //      }
    //    }
  }
}
