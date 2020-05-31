//
// Created by nolasco on 15/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "characters/Character.h"

SCENARIO("Character attacked", "[Character]") {

  GIVEN("Some player") {
    Properties properties{1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u};
    Character player{"Player", "Class", "hi", "bye", properties, Diplomacy::friendly};
    Character player2{"Player", "No idea", "hi", "bye", properties, Diplomacy::friendly};
    REQUIRE(player.properties.health == 1u);
    REQUIRE(player.properties.maxHealth == 2u);
    REQUIRE(player.properties.money == 6u);

    WHEN("the player is pays 5 coins") {
      player.pay(5u);

      THEN("the money decreases correctly") {
        REQUIRE(player.properties.money == 1u);
      }
    }
    AND_WHEN("the player gets payed 15 coins") {
      player.getPayment(15u);

      THEN("the money increases correctly") {
        REQUIRE(player.properties.money == 21u);
      }
    }
  }
}
