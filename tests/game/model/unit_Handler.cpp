//
// Created by nolasco on 28/11/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/trompeloeil.hpp>

#include "game/utilities/Comparators.h"
#include "mocks/CleanerMock.h"
#include "mocks/FactoryMock.h"
#include "mocks/LookupMock.h"
#include "model/World.h"
#include "model/handler/Handler.h"

SCENARIO("Handling of character methods", "[Handler]") {

  GIVEN("A handler instance") {
    auto world = std::make_shared<model::World>();
    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<model::Handler>(world, factory, cleaner, lookup);

    auto character = entity::Character{"character", Stats{}, Info{}};
    auto building = entity::Building{"building", BuildingType::UNDEFINED, Size{}, 0};
    auto consumable = entity::Consumable{"consumable", ConsumableType::UNDEFINED, ItemEffect{}, 0, 1, 2, 3};
    auto equippable = entity::Equippable{"equippable", EquippableType::UNDEFINED, ItemEffect{}, 0, 1, 2, 3};
    auto exterior = entity::Exterior{"exterior", Size{}};
    auto structure = entity::Structure{"structure", StructureType::UNDEFINED, Size{}};
    auto team = entity::Team{"team"};

    world->characters.emplace(1, character);
    world->buildings.emplace(2, building);
    world->consumables.emplace(3, consumable);
    world->equippables.emplace(4, equippable);
    world->exteriors.emplace(5, exterior);
    world->structures.emplace(6, structure);
    world->teams.emplace(7, team);

    WHEN("The characters in the world are querried") {
      handler->renameCharacter(1, "newName");

      THEN("The correct characters are returned") {
        REQUIRE(world->characters.find(1)->second.name == "newName");
      }
    }
  }
}
