//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "utils/database/Database.h"

namespace constants {
constexpr auto potato = "potato";
constexpr auto onion = "onion";
constexpr auto orange = "orange";
}; // namespace constants

SCENARIO("Create entry in shopping list", "[Database]") {

  GIVEN("A shopping list") {
    Database<std::string> shoppingList;
    REQUIRE(shoppingList.size() == 0);

    WHEN("an entry is added is added") {
      const auto entryId = shoppingList.createEntry(constants::potato);
      const auto entry2Id = shoppingList.createEntry(constants::onion);

      THEN("the shopping list size increases") {
        REQUIRE(shoppingList.size() == 2);
        REQUIRE(entryId != entry2Id);
      }
    }
  }
}

SCENARIO("Read entry by Id", "[Database]") {

  GIVEN("A shopping list") {
    Database<std::string> shoppingList;
    const auto entry1Id = shoppingList.createEntry(constants::potato);

    WHEN("the info for that connection is accessed") {
      const auto entryInfo = shoppingList.readEntry(entry1Id);
      THEN("that info matches the one on the insertion") {
        REQUIRE(entryInfo == constants::potato);
      }
    }
  }
}

SCENARIO("Delete entry", "[Database]") {

  GIVEN("A shopping list with two items") {
    Database<std::string> shoppingList;
    const auto entryId = shoppingList.createEntry(constants::potato);
    const auto entry2Id = shoppingList.createEntry(constants::onion);

    WHEN("one entry is removed") {
      shoppingList.deleteEntry(entryId);
      THEN("that entry is no longer accessible, but the remaining connection are not affected") {
        CHECK_THROWS(shoppingList.readEntry(entryId));

        REQUIRE(shoppingList.readEntry(entry2Id) == constants::onion);
        REQUIRE(shoppingList.size() == 1);
      }
    }
  }
}

SCENARIO("Update entry", "[Database]") {

  GIVEN("A shopping list") {
    Database<std::string> shoppingList;
    const auto entryId = shoppingList.createEntry(constants::potato);

    WHEN("an entry is updated") {
      shoppingList.updateEntry(entryId, constants::orange);
      THEN("the results come as expected") {
        REQUIRE(shoppingList.readEntry(entryId) == constants::orange);
      }
    }
  }
}
