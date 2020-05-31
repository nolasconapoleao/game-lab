//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "common/Inventory.h"
#include "items/Item.h"

SCENARIO("Sanity check", "[Inventory]") {

  GIVEN("An inventory") {
    Inventory inventory;

    WHEN("an item is added to that inventory") {
      Item potion{"potion", "description", Effect::speed, UseType::equip, 2u, 2u, 2u};
      inventory.addItem(potion, 2);

      THEN("the item in the first position is the inserted item") {
        const auto itemRetrieved = inventory.getItem(0);
        REQUIRE(itemRetrieved.name == "potion");
        REQUIRE(itemRetrieved.description == "description");
      }
    }
  }
}

SCENARIO("Operations in inventory", "[Inventory]") {

  GIVEN("An inventory with potions and a sword, swords don't stack") {
    Inventory inventory;

    inventory.addItem(Item("Potion", "Is a potion", Effect::health, UseType::consume, 1u, 3u, 1u), 3);
    inventory.addItem(Item("Sword", "Is a sword", Effect::attack, UseType::equip, 10u, 3u, 1u));
    inventory.addItem(Item("Sword", "Is a sword", Effect::attack, UseType::equip, 10u, 3u, 1u));
    REQUIRE(inventory.entries[0].item.name == "Potion");
    REQUIRE(inventory.entries[0].quantity == 3);
    REQUIRE(inventory.entries.size() == 3);

    WHEN("a potion is consumed") {
      inventory.useItem(0);

      THEN("the quantity of potions decreases correctly") {
        REQUIRE(inventory.entries[0].quantity == 2);
      }
    }

    AND_WHEN("all potions are consumed") {
      inventory.useItem(0);
      inventory.useItem(0);
      inventory.useItem(0);

      THEN("the item is dropped item that no longer exists") {
        REQUIRE(inventory.entries.size() == 2);
      }
    }
  }
}
