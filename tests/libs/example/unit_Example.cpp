//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "game/model/state/Tutorial.h"

SCENARIO("Use this to create a target for testing macro states", "[Example]") {

  model::state::Tutorial tutorial;
  tutorial.start();

  while (true) {
    tutorial.whatsUp();
  }
}
