//
// Created by nolasco on 28/11/20.
//

// TODO(nn): Catch main should only be compiled once, for faster compilation
#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <trompeloeil/include/trompeloeil.hpp>

#include "game/utilities/Comparators.h"
#include "model/World.h"
#include "model/factory/Factory.h"

SCENARIO("Creation of character", "[Factory][Character]") {

  GIVEN("A factory instance") {
    auto world = std::make_shared<model::World>();
    auto factory = std::make_shared<model::Factory>(world);

    WHEN("A character is created") {
      const auto creationId = factory->createCharacter(ThreatLevel::NOVICE);
      const auto &creation = world->characters.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->characters.size() == 1);
        REQUIRE(Race::UNDEFINED != creation.info.race);
        REQUIRE(AttackType::UNDEFINED != creation.info.attackType);
        REQUIRE(Occupation::UNDEFINED != creation.info.occupation);
      }
    }
  }
}

SCENARIO("Creation of items", "[Factory][Item]") {

  GIVEN("A factory instance") {
    auto world = std::make_shared<model::World>();
    auto factory = std::make_shared<model::Factory>(world);

    WHEN("An equippable item is created") {
      const auto creationId = factory->createEquippable();
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("An equipment item is created") {
      const auto creationId = factory->createEquipment();
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("A staff item is created") {
      const auto creationId = factory->createStaff();
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("A weapon item is created") {
      const auto creationId = factory->createWeapon();
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("A consumable item is created") {
      const auto creationId = factory->createConsumable();
      const auto &creation = world->consumables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->consumables.size() == 1);
        REQUIRE(ConsumableType::UNDEFINED != creation.type);
        REQUIRE(creation.duration > 0);
        REQUIRE(!creation.consumed);
      }
    }
  }
}

SCENARIO("Creation of locations", "[Factory][Location]") {

  GIVEN("A factory instance") {
    auto world = std::make_shared<model::World>();
    auto factory = std::make_shared<model::Factory>(world);

    WHEN("A building is created") {
      const auto creationId = factory->createBuilding();
      const auto &creation = world->buildings.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->buildings.size() == 1);
        REQUIRE(BuildingType::UNDEFINED != creation.type);
        REQUIRE(0 != creation.health);
        REQUIRE(0 != creation.floors);
      }
    }

    AND_WHEN("A connector is created") {
      const auto creationId = factory->createConnector();
      const auto &creation = world->exteriors.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->exteriors.size() == 1);
        REQUIRE(0 != creation.size.width);
        REQUIRE(0 != creation.size.height);
      }
    }

    AND_WHEN("An exterior location is created") {
      const auto creationId = factory->createLocation();
      const auto &creation = world->exteriors.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->exteriors.size() == 1);
        REQUIRE(0 != creation.size.width);
        REQUIRE(0 != creation.size.height);
      }
    }
  }
}

SCENARIO("Creation of structures", "[Factory][Structure]") {

  GIVEN("A factory instance") {
    auto world = std::make_shared<model::World>();
    auto factory = std::make_shared<model::Factory>(world);

    WHEN("A structure is created") {
      const auto creationId = factory->createStructure();
      const auto &creation = world->structures.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->structures.size() == 1);
        REQUIRE(StructureType::UNDEFINED != creation.type);
        REQUIRE(0 != creation.health);
        REQUIRE(0 != creation.size.width);
        REQUIRE(0 != creation.size.height);
      }
    }
  }
}
