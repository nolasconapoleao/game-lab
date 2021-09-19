//
// Created by nolasco on 01/12/20.
//

#include <main_test.h>

#include "controller/brain/PlayerBrain.h"
#include "datatypes/constants/gameconstants.h"
#include "mocks/InputCaptureMock.h"
#include "mocks/SnapshotMock.h"

// TODO(nn): Create a macro for the required calls
SCENARIO("Player terminates game", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      Snapshot snapshot = testHelper::createSnapshotMock();
      trompeloeil::sequence seq;

      REQUIRE_CALL(mock, alphanum(trompeloeil::_))
          .RETURN(gameconstants::submenuInfo(Action::MENU).transition)
          .IN_SEQUENCE(seq);
      REQUIRE_CALL(mock, alphanum(trompeloeil::_))
          .RETURN(gameconstants::submenuInfo(Action::MENU_TERMINATE).transition)
          .IN_SEQUENCE(seq);

      controller::brain::Player player{};
      auto decision = player.think(snapshot);
      THEN("The player terminates the game") {
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}

SCENARIO("Player attacks game entities", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      Snapshot snapshot = testHelper::createSnapshotMock();
      controller::brain::Player player{};

      trompeloeil::sequence seq;
      THEN("The player attacks a character") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::ATTACK).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::ATTACK_CHARACTER).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::ATTACK_CHARACTER == decision.action);
      }

      AND_THEN("The player attacks a structure") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::ATTACK).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::ATTACK_STRUCTURE).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::ATTACK_STRUCTURE == decision.action);
      }

      AND_THEN("The player attacks a building") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::ATTACK).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::ATTACK_BUILDING).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::ATTACK_BUILDING == decision.action);
      }

      AND_THEN("The player terminates the game") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::MENU).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::MENU_TERMINATE).transition)
            .IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}

SCENARIO("Player uses inventory options", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      Snapshot snapshot = testHelper::createSnapshotMock();
      controller::brain::Player player{};

      trompeloeil::sequence seq;
      THEN("The player picks up an item") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::INVENTORY).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::INVENTORY_PICKUP).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::INVENTORY_PICKUP == decision.action);
      }

      AND_THEN("The player uses an item") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::INVENTORY).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::INVENTORY_USE).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::INVENTORY_USE == decision.action);
      }

      AND_THEN("The player drops an item") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::INVENTORY).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::INVENTORY_DROP).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::INVENTORY_DROP == decision.action);
      }

      AND_THEN("The player terminates the game") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::MENU).transition)
            .IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_))
            .RETURN(gameconstants::submenuInfo(Action::MENU_TERMINATE).transition)
            .IN_SEQUENCE(seq);
        auto decision = player.think(snapshot);
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}
