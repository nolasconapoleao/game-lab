//
// Created by nolasco on 28/11/20.
//

#include <main_test.h>

#include "game/utilities/Comparators.h"
#include "mocks/CleanerMock.h"
#include "mocks/FactoryMock.h"
#include "mocks/LookupMock.h"
#include "mocks/WorldMock.h"
#include "model/handler/Handler.h"

namespace t = trompeloeil;

SCENARIO("World creation methods", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = std::make_shared<model::World>();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    WHEN("The world is created") {
      REQUIRE_CALL(*factory.get(), createCharacter(t::_, t::_, t::_, t::_))
          .LR_SIDE_EFFECT(world->characters.emplace(1, testHelper::cCharacter))
          .TIMES(AT_LEAST(1))
          .RETURN(1);
      REQUIRE_CALL(*factory.get(), createEquippable(t::_)).TIMES(AT_LEAST(1)).RETURN(1);
      REQUIRE_CALL(*factory.get(), createConsumable(t::_, t::_)).TIMES(AT_LEAST(1)).RETURN(1);
      REQUIRE_CALL(*factory.get(), createConnector(t::_)).TIMES(AT_LEAST(1)).RETURN(1);
      REQUIRE_CALL(*factory.get(), createBuilding(t::_)).TIMES(AT_LEAST(1)).RETURN(1);
      REQUIRE_CALL(*factory.get(), createLocation(t::_)).TIMES(AT_LEAST(1)).RETURN(1);
      REQUIRE_CALL(*factory.get(), createStructure(t::_)).TIMES(AT_LEAST(1)).RETURN(1);

      THEN("All game entity creation methods are called") {
        handler->createWorld();
      }
    }
  }
}

SCENARIO("World destruction methods", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = testHelper::createWorldMock();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    WHEN("The world is destroyed") {
      THEN("The world entities are empty") {
        handler->destroyWorld();
        REQUIRE(world->characters.empty());
        REQUIRE(world->consumables.empty());
        REQUIRE(world->equippables.empty());
        REQUIRE(world->exteriors.empty());
        REQUIRE(world->buildings.empty());
        REQUIRE(world->structures.empty());
        REQUIRE(world->teams.empty());
        REQUIRE(world->neighbours.empty());
        REQUIRE(world->locatedIn.empty());
        REQUIRE(world->memberships.empty());
      }
    }
  }
}

SCENARIO("Handling of travel", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = testHelper::createWorldMock();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    WHEN("A character travels to another location") {
      handler->travel(testHelper::cCharacterId, testHelper::cExterior2Id);

      THEN("The traveller is correctly sent to the new location") {
        REQUIRE(world->locatedIn.find(testHelper::cCharacterId)->second == testHelper::cExterior2Id);
      }
    }
  }
}

SCENARIO("Handling of possession", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = testHelper::createWorldMock();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    WHEN("A character attempts a possession") {
      handler->possess(testHelper::cCharacterId, testHelper::cCharacter2Id);

      THEN("The possession succeeds if the stats are superior on the mage side") {
        REQUIRE(world->characters.find(testHelper::cCharacterId)->second.info.ghost == Ghost::COMPUTER);
      }
    }
  }
}

SCENARIO("Handling of character renaming", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = testHelper::createWorldMock();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    WHEN("The characters in the world are renamed") {
      handler->renameCharacter(testHelper::cCharacterId, "newName");

      THEN("The character is correctly renamed") {
        REQUIRE(world->characters.find(testHelper::cCharacterId)->second.name == "newName");
      }
    }
  }
}

SCENARIO("Handling of team renaming", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = testHelper::createWorldMock();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    WHEN("The tean is correctly renamed") {
      handler->renameTeam(testHelper::cTeamId, "newName");

      THEN("The team is correctly renamed") {
        REQUIRE(world->teams.find(testHelper::cTeamId)->second.name == "newName");
      }
    }
  }
}
