//
// Created by nolasco on 01/12/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/catch2/trompeloeil.hpp>

#include "controller/brain/PlayerBrain.h"
#include "mocks/InputCaptureMock.h"

SCENARIO("Player strategizes", "[Player]") {
  GIVEN("A world snapshot object containing a shopkeeper") {
    WHEN("The lookup utilities are called") {

      auto c = entity::Character{"character", Stats{}, Info{}};
      auto cEntry = DbEntry<entity::Character>{1, std::make_shared<entity::Character>(c)};
      auto cEnemy = DbEntry<entity::Character>{2, std::make_shared<entity::Character>(c)};
      Snapshot snapshot{cEntry};
      snapshot.characters.emplace_back(cEnemy);

      controller::brain::Player player{};

      std::vector<char> input{'a', 'c', '1', 'x'};
      REQUIRE_CALL(mock, alphanum(trompeloeil::_)).LR_RETURN('x');

      auto decision = player.think(snapshot);
      THEN("The call is successful and the expected result is returned") {
        REQUIRE(Action::SKIP_TURN == decision.action);
      }
    }
  }
}
