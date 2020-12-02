//
// Created by nolasco on 28/11/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/trompeloeil.hpp>

#include "controller/GameEngine.h"
#include "mocks/CleanerMock.h"
#include "mocks/FactoryMock.h"
#include "mocks/HandlerMock.h"
#include "mocks/LookupMock.h"
#include "model/World.h"

SCENARIO("Game engine validation", "[Main]") {

  GIVEN("The multiple game objects") {
    // Model classes
    auto world = std::make_shared<model::World>();

    auto lookup = std::make_shared<LookupMock>();
    auto factory = std::make_shared<FactoryMock>();
    auto cleaner = std::make_shared<CleanerMock>();
    auto handler = std::make_shared<HandlerMock>();

    ALLOW_CALL(*handler.get(), createWorld());

    auto c = entity::Character{"character", Stats{}, Info{}};
    auto cEntry = DbEntry<entity::Character>{1, std::make_shared<entity::Character>(c)};
    std::vector<DbEntry<entity::Character>> playableCharacter = {cEntry};
    std::vector<DbEntry<entity::Character>> closeByCharacter = {};

    ALLOW_CALL(*lookup.get(), playableCharacters()).RETURN(playableCharacter);
    ALLOW_CALL(*lookup.get(), closeByCharacters(1)).RETURN(closeByCharacter);
    ALLOW_CALL(*lookup.get(), characterExists(1)).RETURN(true);
    ALLOW_CALL(*lookup.get(), character(1)).RETURN(cEntry.entity);

    auto l = entity::Location{"location", Size{1, 2}};
    auto lEntry = DbEntry<entity::Location>{2, std::make_shared<entity::Location>(l)};
    ALLOW_CALL(*lookup.get(), whereIs(1)).RETURN(lEntry);

    auto itemsIn = std::vector<DbEntry<entity::Item>>{};
    auto consumablesIn = std::vector<DbEntry<entity::Consumable>>{};
    auto equippablesIn = std::vector<DbEntry<entity::Equippable>>{};
    auto charactersIn = std::vector<DbEntry<entity::Character>>{};
    auto structuresIn = std::vector<DbEntry<entity::Structure>>{};
    auto neighbourExteriors = std::vector<DbEntry<entity::Exterior>>{};
    auto neighbourBuildings = std::vector<DbEntry<entity::Building>>{};
    auto closeByLocations = std::vector<DbEntry<entity::Location>>{};

    ALLOW_CALL(*lookup.get(), itemsIn(trompeloeil::_)).RETURN(itemsIn);
    ALLOW_CALL(*lookup.get(), consumablesIn(trompeloeil::_)).RETURN(consumablesIn);
    ALLOW_CALL(*lookup.get(), equippablesIn(trompeloeil::_)).RETURN(equippablesIn);
    ALLOW_CALL(*lookup.get(), charactersIn(trompeloeil::_)).RETURN(charactersIn);
    ALLOW_CALL(*lookup.get(), structuresIn(trompeloeil::_)).RETURN(structuresIn);
    ALLOW_CALL(*lookup.get(), closeByStructures(trompeloeil::_)).RETURN(structuresIn);
    ALLOW_CALL(*lookup.get(), closeByBuildings(trompeloeil::_)).RETURN(neighbourBuildings);
    ALLOW_CALL(*lookup.get(), neighbourExteriors(trompeloeil::_)).RETURN(neighbourExteriors);
    ALLOW_CALL(*lookup.get(), closeByExteriors(trompeloeil::_)).RETURN(neighbourExteriors);
    ALLOW_CALL(*lookup.get(), neighbourBuildings(trompeloeil::_)).RETURN(neighbourBuildings);
    ALLOW_CALL(*lookup.get(), closeByLocations(trompeloeil::_)).RETURN(closeByLocations);

    // Controller classes
    auto controller = std::make_shared<controller::GameEngine>(handler, lookup);

    WHEN("The game cycle is run") {
      CHECK_NOTHROW(controller->run());
      THEN("No exception is thrown") {
      }
    }
  }
}
