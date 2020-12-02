//
// Created by nolasco on 01/12/20.
//
#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>

#include "controller/DecisionChecker.h"
#include "datatypes/controller/Decision.h"
#include "datatypes/lookup/ResourceEntry.h"

SCENARIO("Decision handling", "[DecisionChecker]") {
  GIVEN("A world snapshot and decision are generated") {
    Snapshot snapshot{};
    Decision decision{};

    WHEN("The combination of paramenters are checked ") {

      THEN("The check returns a valid play") {
        controller::DecisionChecker checker;
        REQUIRE(checker.isDecisionValid(snapshot, decision));
      }
    }
  }
}
