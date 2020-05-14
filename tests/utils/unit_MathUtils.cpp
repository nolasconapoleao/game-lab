//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "utils/MathUtils.h"

using namespace MathUtils;

SCENARIO("Clamped addition", "[MathUtils]") {

  GIVEN("Some addition operators and some upper bound") {
    uint augend = 1u;
    uint addend = 2u;
    uint upperBound = 1u;
    uint upperBound_2nd = 4u;

    WHEN("the result is higher than the upper bound the return value equals the upper bound") {
      THEN("the fields return the correct values") {
        REQUIRE(clamp_add(addend, augend, upperBound) == 1u);
        REQUIRE(clamp_add(addend, augend, upperBound_2nd) == 3u);
      }
    }
  }
}

SCENARIO("Clamped subtraction", "[MathUtils]") {

  GIVEN("Some subtraction operators and some lower bound") {
    uint minuend = 3u;
    uint subtrahend = 2u;
    uint lowerBound = 0u;
    uint lowerBound_2nd = 2u;

    WHEN("the result is higher than the lower bound the return value equals the lower bound") {
      THEN("the fields return the correct values") {
        REQUIRE(clamp_sub(minuend, subtrahend, lowerBound) == 1u);
        REQUIRE(clamp_sub(minuend, subtrahend, lowerBound_2nd) == 2u);
      }
    }
  }
}

SCENARIO("Clamped number", "[MathUtils]") {

  GIVEN("Some number and some upper and lower bounds") {
    uint num = 1u;
    uint num_2nd = 3u;
    uint num_3nd = 6u;
    uint lowerBound = 2u;
    uint upperBound = 4u;

    WHEN("the number is higher than the upper bound the return value equals the upper bound") {
      THEN("the fields return the correct values") {
        REQUIRE(clamp(num, lowerBound, upperBound) == 2u);
        REQUIRE(clamp(num_2nd, lowerBound, upperBound) == 3u);
        REQUIRE(clamp(num_3nd, lowerBound, upperBound) == 4u);
      }
    }
  }
}
