//
// Created by nolasco on 15/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "characters/Player.h"

SCENARIO("Player attacked", "[Player]") {

  GIVEN("Some player") {
    Player player;
    REQUIRE(player.maxHealthPoints == 20);
    REQUIRE(player.currentHealthPoints == 20);
    REQUIRE(player.attackPoints == 3);

    WHEN("the player is attacked twice with a 5 point attack") {
      THEN("the health points drop 10 from the initial 20") {
        player.receiveAttack(5u);
        player.receiveAttack(5u);
        REQUIRE(player.currentHealthPoints == 10);
      }
    }
  }
}
