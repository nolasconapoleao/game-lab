//
// Created by nolasco on 28/11/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/trompeloeil.hpp>

#include "game/utilities/Comparators.h"
#include "model/World.h"
#include "model/lookup/Lookup.h"

SCENARIO("Lookup character retrieval methods", "[Main]") {

  GIVEN("A lookup instance") {
    auto world = std::make_shared<model::World>();

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

    auto lookup = std::make_shared<model::Lookup>(world);

    WHEN("The characters in the world are querried") {
      auto resultCharacter = lookup->character(1);

      THEN("The correct characters are returned") {
        REQUIRE(compare(*resultCharacter.get(), character));
      }
    }
  }
}
