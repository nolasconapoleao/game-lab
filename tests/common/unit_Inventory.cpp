//
// Created by nolasco on 14/05/20.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#define private public

#include "common/Inventory.h"
#include "items/Item.h"
#include "utils/PrintUtils.cpp"

SCENARIO("Sanity check", "[Inventory]") {

  GIVEN("An inventory with no items.csv") {
    Inventory inventory;

    WHEN("any operation is called") {
      THEN("all operation return false") {
        REQUIRE_FALSE(inventory.consumeItem(1));
        REQUIRE_FALSE(inventory.dropItem(1));

        REQUIRE_FALSE(inventory.equipItem(1));
        REQUIRE_FALSE(inventory.unequipItem(1));
      }
    }
  }
}

SCENARIO("Operations in consumables", "[Inventory]") {

  GIVEN("An inventory with potions") {
    Inventory inventory;

    inventory.addItem(Item("Potion", "Is a potion", Effect::health, UseType::consume, 3u, 1u));
    inventory.addItem(Item("Potion", "Is a potion", Effect::health, UseType::consume, 3u, 1u));
    inventory.addItem(Item("Potion", "Is a potion", Effect::health, UseType::consume, 3u, 1u));
    REQUIRE(inventory.consumables[0].item.name == "Potion");
    REQUIRE(inventory.consumables[0].quantity == 3);

    WHEN("a potion is consumed") {
      REQUIRE(inventory.consumeItem(1));

      THEN("the quantity of potions decreases correctly") {
        REQUIRE(inventory.consumables[0].quantity == 2);
      }
    }

    AND_WHEN("all potions are consumed") {
      REQUIRE(inventory.consumeItem(1));
      REQUIRE(inventory.consumeItem(1));
      REQUIRE(inventory.consumeItem(1));

      THEN("Access to an item that no longer exists, yields false") {
        REQUIRE(inventory.consumables[0].quantity == 0);
        REQUIRE_FALSE(inventory.consumeItem(1));
      }
    }
  }
}

SCENARIO("Operations in equipables", "[Inventory]") {

  GIVEN("An inventory with swords") {
    Inventory inventory;

    inventory.addItem(Item("Sword", "Is a sword", Effect::attack, UseType::equip, 2u, 1u));
    REQUIRE(inventory.equipables[0].item.name == "Sword");
    REQUIRE(inventory.equipables[0].equipped == false);

    inventory.addItem(Item("Sword", "Is a sword", Effect::attack, UseType::equip, 2u, 1u));
    REQUIRE(inventory.equipables[1].item.name == "Sword");
    REQUIRE(inventory.equipables[1].equipped == false);

    WHEN("a series of equips and unequips is requested") {

      THEN("the operations happen correctly") {
        REQUIRE(inventory.equipItem(1));
        REQUIRE(inventory.equipables[0].equipped == true);

        REQUIRE_FALSE(inventory.equipItem(2));
        REQUIRE(inventory.equipables[1].equipped == false);

        REQUIRE(inventory.unequipItem(1));
        REQUIRE(inventory.equipables[0].equipped == false);
      }
    }
  }
}
