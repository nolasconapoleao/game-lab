//
// Created by nolasco on 28/11/20.
//

#include <main_test.h>

#include "game/utilities/Comparators.h"
#include "mocks/LookupMock.h"
#include "model/World.h"
#include "model/cleaner/Cleaner.h"

SCENARIO("Cleanup of character methods", "[Cleaner]") {

  GIVEN("A cleanup instance") {
    auto world = std::make_shared<model::World>();
    auto lookup = std::make_shared<LookupMock>();
    auto cleaner = std::make_shared<model::Cleaner>(world, lookup);

    auto itemsIn = std::vector<DbEntry<entity::Item>>{};
    auto charactersIn = std::vector<DbEntry<entity::Character>>{};
    auto structuresIn = std::vector<DbEntry<entity::Structure>>{};
    auto closeByLocations = std::vector<DbEntry<entity::Location>>{};
    ALLOW_CALL(*lookup.get(), itemsIn(trompeloeil::_)).RETURN(itemsIn);
    ALLOW_CALL(*lookup.get(), charactersIn(trompeloeil::_)).RETURN(charactersIn);
    ALLOW_CALL(*lookup.get(), structuresIn(trompeloeil::_)).RETURN(structuresIn);
    ALLOW_CALL(*lookup.get(), neighboursEndingIn(trompeloeil::_)).RETURN(closeByLocations);

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

    WHEN("The game entities in the world are deleted") {
      cleaner->deleteCharacter(1);
      cleaner->deleteBuilding(2);
      cleaner->deleteConsumable(3);
      cleaner->deleteEquipable(4);
      cleaner->deleteLocation(5);
      cleaner->deleteStructure(6);

      THEN("No entities remain") {
        REQUIRE(world->characters.empty());
        REQUIRE(world->buildings.empty());
        REQUIRE(world->consumables.empty());
        REQUIRE(world->equippables.empty());
        REQUIRE(world->exteriors.empty());
        REQUIRE(world->structures.empty());
      }
    }
  }
}
