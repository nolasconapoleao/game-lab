//
// Created by nolasco on 28/11/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/catch2/trompeloeil.hpp>

#include "controller/brain/ComputerBrain.h"
#include "mocks/RandomMock.h"

SCENARIO("Computer strategizes", "[Brain]") {
  GIVEN("A world snapshot object containing a shopkeeper") {
    WHEN("The lookup utilities are called") {

      auto c = entity::Character{"character", Stats{}, Info{}};
      auto cEntry = DbEntry<entity::Character>{1, std::make_shared<entity::Character>(c)};
      auto cEnemy = DbEntry<entity::Character>{2, std::make_shared<entity::Character>(c)};
      Snapshot snapshot{cEntry};
      snapshot.characters.emplace_back(cEnemy);

      controller::brain::Computer computer{};
      ALLOW_CALL(mock, rand(trompeloeil::_, trompeloeil::_)).RETURN(2);

      auto decision = computer.think(snapshot);
      THEN("The call is successful and the expected result is returned") {
        REQUIRE(Action::SKIP_TURN == decision.action);
      }
    }
  }
}
