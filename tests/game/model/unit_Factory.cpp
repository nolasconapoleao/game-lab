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
      auto race = GENERATE(as<Race>{}, Race::DEMON, Race::DRAGON, Race::ELF, Race::GIANT, Race::HUMAN, Race::ORC,
                           Race::TROLL, Race::GOBLIN, Race::UNDEFINED);
      auto attackType = GENERATE(as<AttackType>{}, AttackType::CONJURING, AttackType::ELEMENTAL, AttackType::MAGIC,
                                 AttackType::PHYSICAL, AttackType::SUPPORT, AttackType::UNDEFINED);
      auto occupation = GENERATE(as<Occupation>{}, Occupation::BEGGAR, Occupation::BLACKSMITH, Occupation::JESTER,
                                 Occupation::LIBRARIAN, Occupation::MERCENARY, Occupation::SHOPKEEPER,
                                 Occupation::THIEF, Occupation::TOURIST, Occupation::UNDEFINED);
      auto threat = GENERATE(as<ThreatLevel>{}, ThreatLevel::SCARECROW, ThreatLevel::NOVICE, ThreatLevel::ACE,
                             ThreatLevel::VETERAN, ThreatLevel::MONSTER, ThreatLevel::GOD);

      const auto creationId = factory->createCharacter(threat, attackType, race, occupation);
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
      auto type = GENERATE(as<EquippableType>{}, EquippableType::EQUIPMENT, EquippableType::STAFF,
                           EquippableType::WEAPON, EquippableType::UNDEFINED);
      const auto creationId = factory->createEquippable(type);
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("An equipment item is created") {
      auto type = GENERATE(as<EquipmentType>{}, EquipmentType::COAT, EquipmentType::SHIELD, EquipmentType::SKATE,
                           EquipmentType::UNDEFINED);
      const auto creationId = factory->createEquipment(type);
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("A staff item is created") {
      auto type
          = GENERATE(as<StaffType>{}, StaffType::CONJURING, StaffType::DARK, StaffType::SUPPORT, StaffType::UNDEFINED);
      const auto creationId = factory->createStaff(type);
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("A weapon item is created") {
      auto type = GENERATE(as<WeaponType>{}, WeaponType::AXE, WeaponType::BOW, WeaponType::DAGGER, WeaponType::KNIFE,
                           WeaponType::LONGBOW, WeaponType::SWORD, WeaponType::UNDEFINED);
      const auto creationId = factory->createWeapon(type);
      const auto &creation = world->equippables.find(creationId)->second;

      THEN("The creation is available in the world and all parameters are correctly initialized") {
        REQUIRE(world->equippables.size() == 1);
        REQUIRE(EquippableType::UNDEFINED != creation.type);
        REQUIRE(creation.uses > 0);
        REQUIRE(!creation.equipped);
      }
    }

    AND_WHEN("A consumable item is created") {
      auto type = GENERATE(as<ConsumableType>{}, ConsumableType::COIN, ConsumableType::ELIXIR, ConsumableType::POISON,
                           ConsumableType::POTION, ConsumableType::UNDEFINED);
      const auto creationId = factory->createConsumable(type);
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
      auto type
          = GENERATE(as<BuildingType>{}, BuildingType::ARENA, BuildingType::BARN, BuildingType::HOME,
                     BuildingType::HOSPITAL, BuildingType::LIBRARY, BuildingType::MUSEUM, BuildingType::SALOON,
                     BuildingType::SHOP, BuildingType::SKYSCRAPER, BuildingType::STORAGE, BuildingType::UNDEFINED);
      const auto creationId = factory->createBuilding(type);
      const auto &creation = world->buildings.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->buildings.size() == 1);
        REQUIRE(BuildingType::UNDEFINED != creation.type);
        REQUIRE(0 != creation.health);
        REQUIRE(0 != creation.floors);
      }
    }

    AND_WHEN("A connector is created") {
      auto type = GENERATE(as<ConnectorType>{}, ConnectorType::BRIDGE, ConnectorType::CAVE, ConnectorType::RIVER,
                           ConnectorType::TUNNEL, ConnectorType::UNDEFINED);
      const auto creationId = factory->createConnector(type);
      const auto &creation = world->exteriors.find(creationId)->second;

      THEN("The creation is available in the world and does not use placeholder values") {
        REQUIRE(world->exteriors.size() == 1);
        REQUIRE(0 != creation.size.width);
        REQUIRE(0 != creation.size.height);
      }
    }

    AND_WHEN("An exterior location is created") {
      auto type = GENERATE(as<ExteriorType>{}, ExteriorType::CITY, ExteriorType::TOWN, ExteriorType::VILLAGE,
                           ExteriorType::UNDEFINED);
      const auto creationId = factory->createLocation(type);
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
      auto type
          = GENERATE(as<StructureType>{}, StructureType::UNDEFINED, StructureType::MAILBOX, StructureType::PHONEBOOTH);
      const auto creationId = factory->createStructure(type);
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
