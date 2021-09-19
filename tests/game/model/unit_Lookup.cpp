//
// Created by nolasco on 28/11/20.
//

#include <main_test.h>

#include "game/utilities/Comparators.h"
#include "model/World.h"
#include "model/lookup/Lookup.h"

SCENARIO("Lookup of character methods", "[Lookup]") {

  GIVEN("A lookup instance") {
    auto world = std::make_shared<model::World>();
    auto lookup = std::make_shared<model::Lookup>(world);

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

    WHEN("The characters in the world are queried") {
      auto resultCharacter = lookup->character(1);

      THEN("The correct characters are returned") {
        REQUIRE(compare(*resultCharacter.get(), character));
      }
    }
  }
}
