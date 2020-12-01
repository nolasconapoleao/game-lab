//
// Created by nolasco on 01/12/20.
//
#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>

#include "controller/DecisionChecker.h"
#include "datatypes/controller/Decision.h"
#include "datatypes/lookup/ResourceEntry.h"

SCENARIO("Snapshot handling", "[DecisionChecker]") {
  GIVEN("A world snapshot object containing a shopkeeper") {
    Snapshot snapshot{};
    Decision decision{};

    WHEN("The lookup utilities are called") {

      THEN("The call is successful and the expected result is returned") {
        controller::DecisionChecker checker;
        REQUIRE(checker.isDecisionValid(snapshot, decision));
      }
    }
  }
}
