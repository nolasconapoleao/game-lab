//
// Created by nolasco on 15/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "characters/Character.h"

SCENARIO("Character attacked", "[Character]") {

  GIVEN("Some player") {
    Character player{"Player", "No idea", "hi", "bye", 20, 3, Diplomacy::friendly};
    Character player2{"Player", "No idea", "hi", "bye", 20, 5, Diplomacy::friendly};
    REQUIRE(player.properties.health == 20);
    REQUIRE(player.properties.maxHealth == 20);
    REQUIRE(player.properties.attack == 3);

    WHEN("the player is attacked by a 5 point attack") {
      THEN("the health points drop depending on the hit success") {
        auto hitSuccess = player.attackedBy(player2);
        if (hitSuccess) {
          REQUIRE(player.properties.health == 15);
        } else {
          REQUIRE(player.properties.health == 20);
        }
      }
    }
  }
}
