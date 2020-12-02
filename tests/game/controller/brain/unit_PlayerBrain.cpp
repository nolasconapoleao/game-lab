//
// Created by nolasco on 01/12/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/catch2/trompeloeil.hpp>

#include "controller/brain/PlayerBrain.h"
#include "mocks/InputCaptureMock.h"

SCENARIO("Player strategizes", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      auto character = entity::Character{"character", Stats{}, Info{}};
      auto location = entity::Location{"location", Size{1, 2}};
      auto exterior = entity::Exterior{"location", Size{1, 2}};
      auto building = entity::Building{"building", BuildingType::UNDEFINED, Size{1, 2}, 0};
      auto consumable = entity::Consumable{"consumable", ConsumableType::UNDEFINED, ItemEffect{}, 0, 0, 0, 0};
      auto equipable = entity::Equippable{"equipable", EquippableType::UNDEFINED, ItemEffect{}, 0, 0, 0, 0};
      auto structure = entity::Structure{"structure", StructureType::UNDEFINED, Size{1, 2}};
      auto item = entity::Item{"item", ItemEffect{}, 0, 0, 0};

      auto characterEntry = DbEntry<entity::Character>{1, std::make_shared<entity::Character>(character)};
      auto locationEntry = DbEntry<entity::Location>{2, std::make_shared<entity::Location>(location)};
      auto charactersEntry = DbEntry<entity::Character>{3, std::make_shared<entity::Character>(character)};
      auto consumablesEntry = DbEntry<entity::Consumable>{4, std::make_shared<entity::Consumable>(consumable)};
      auto equippablesEntry = DbEntry<entity::Equippable>{5, std::make_shared<entity::Equippable>(equipable)};
      auto structuresEntry = DbEntry<entity::Structure>{6, std::make_shared<entity::Structure>(structure)};
      auto buildingsEntry = DbEntry<entity::Building>{7, std::make_shared<entity::Building>(building)};
      auto exteriorsEntry = DbEntry<entity::Exterior>{8, std::make_shared<entity::Exterior>(exterior)};
      auto floorEntry = DbEntry<entity::Item>{9, std::make_shared<entity::Item>(item)};
      auto ownedByEntry = std::map<CharacterId, std::vector<DbEntry<entity::Item>>>{{10, {floorEntry}}};

      Snapshot snapshot{characterEntry,    locationEntry,    {consumablesEntry}, {equippablesEntry}, {characterEntry},
                        {structuresEntry}, {buildingsEntry}, {exteriorsEntry},   {floorEntry},       ownedByEntry};
      controller::brain::Player player{};

      trompeloeil::sequence seq;

      REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('m').IN_SEQUENCE(seq);
      ;
      REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('x').IN_SEQUENCE(seq);
      ;

      auto decision = player.think(snapshot);
      THEN("The player terminates the game") {
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}
