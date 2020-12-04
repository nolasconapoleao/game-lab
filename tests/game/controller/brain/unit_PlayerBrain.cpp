//
// Created by nolasco on 01/12/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/catch2/trompeloeil.hpp>

#include "controller/brain/PlayerBrain.h"
#include "mocks/InputCaptureMock.h"

// TODO (nn): Create snapshot and world mock

class SnapshotWrapper {
public:
  SnapshotWrapper() {
    initSnapshot();
  }

  void initSnapshot() {
    auto character = entity::Character{"character", Stats{}, Info{}};
    auto location = entity::Location{"location", Size{1, 2}};
    auto exterior = entity::Exterior{"location", Size{1, 2}};
    auto building = entity::Building{"building", BuildingType::UNDEFINED, Size{1, 2}, 0};
    auto consumable = entity::Consumable{"consumable", ConsumableType::UNDEFINED, ItemEffect{}, 1, 0, 0, 0};
    auto equipable = entity::Equippable{"equipable", EquippableType::UNDEFINED, ItemEffect{}, 1, 0, 0, 0};
    auto structure = entity::Structure{"structure", StructureType::UNDEFINED, Size{1, 2}};
    auto item = entity::Item{"item", ItemEffect{}, 1, 0, 0};

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

    snapshot = Snapshot{characterEntry,    locationEntry,    {consumablesEntry}, {equippablesEntry}, {characterEntry},
                        {structuresEntry}, {buildingsEntry}, {exteriorsEntry},   {floorEntry},       ownedByEntry};
  }

  const Snapshot &getSnapshot() const {
    return snapshot;
  }

private:
  Snapshot snapshot;
};

SCENARIO("Player terminates game", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      SnapshotWrapper wrapper{};
      wrapper.initSnapshot();

      trompeloeil::sequence seq;
      REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('m').IN_SEQUENCE(seq);
      REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('x').IN_SEQUENCE(seq);

      controller::brain::Player player{};
      auto decision = player.think(wrapper.getSnapshot());
      THEN("The player terminates the game") {
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}

SCENARIO("Player attacks game entities", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      SnapshotWrapper wrapper{};
      controller::brain::Player player{};

      trompeloeil::sequence seq;
      THEN("The player attacks a character") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('a').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('c').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::ATTACK_CHARACTER == decision.action);
      }

      AND_THEN("The player attacks a structure") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('a').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('s').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::ATTACK_STRUCTURE == decision.action);
      }

      AND_THEN("The player attacks a building") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('a').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('b').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::ATTACK_BUILDING == decision.action);
      }

      AND_THEN("The player terminates the game") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('m').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('x').IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}

SCENARIO("Player uses inventory options", "[Player]") {
  GIVEN("A world snapshot") {
    WHEN("The player is asked to decide on a play") {

      SnapshotWrapper wrapper{};
      controller::brain::Player player{};

      trompeloeil::sequence seq;
      THEN("The player picks up an item") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('i').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('p').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::INVENTORY_PICKUP == decision.action);
      }

      AND_THEN("The player uses an item") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('i').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('u').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::INVENTORY_USE == decision.action);
      }

      AND_THEN("The player drops an item") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('i').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('d').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, numeric(trompeloeil::_)).RETURN(1).IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::INVENTORY_DROP == decision.action);
      }

      AND_THEN("The player terminates the game") {
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('m').IN_SEQUENCE(seq);
        REQUIRE_CALL(mock, alphanum(trompeloeil::_)).RETURN('x').IN_SEQUENCE(seq);
        auto decision = player.think(wrapper.getSnapshot());
        REQUIRE(Action::MENU_TERMINATE == decision.action);
      }
    }
  }
}
