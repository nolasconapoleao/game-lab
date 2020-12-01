//
// Created by nolasco on 28/11/20.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>

#include "controller/SnapshotUtilities.h"

SCENARIO("Snapshot handling", "[SnapshotUtilities]") {
  GIVEN("A world snapshot object containing a shopkeeper") {
    Snapshot snapshot{};
    Info info{0, Ghost::COMPUTER, Race::UNDEFINED, AttackType::UNDEFINED, Occupation::SHOPKEEPER};
    auto c = entity::Character{"character", Stats{}, info};
    auto cEntry = DbEntry<entity::Character>{1, std::make_shared<entity::Character>(c)};
    snapshot.characters.emplace_back(cEntry);
    WHEN("The lookup utilities are called") {

      THEN("The call is successful and the expected result is returned") {
        utils::SnapshotUtilities utilities;
        REQUIRE(utilities.shopkeeperAvailable(snapshot));
        REQUIRE_FALSE(utilities.phoneboothAvailable(snapshot));
      }
    }
  }

  GIVEN("A world snapshot object containing a structure") {
    Snapshot snapshot{};
    auto s = entity::Structure{"structure", StructureType::PHONEBOOTH, Size{1, 1}};
    auto sEntry = DbEntry<entity::Structure>{1, std::make_shared<entity::Structure>(s)};
    snapshot.structures.emplace_back(sEntry);
    WHEN("The lookup utilities are called") {

      THEN("The call is successful and the expected result is returned") {
        utils::SnapshotUtilities utilities;
        REQUIRE_FALSE(utilities.shopkeeperAvailable(snapshot));
        REQUIRE(utilities.phoneboothAvailable(snapshot));
      }
    }
  }

  GIVEN("An empty world snapshot object") {
    Snapshot snapshot{};
    WHEN("The lookup utilities are called") {

      THEN("The call is successful and the expected result is returned") {
        utils::SnapshotUtilities utilities;
        REQUIRE_FALSE(utilities.shopkeeperAvailable(snapshot));
        REQUIRE_FALSE(utilities.phoneboothAvailable(snapshot));
      }
    }
  }
}
