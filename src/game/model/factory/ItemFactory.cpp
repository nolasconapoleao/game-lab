//
// Created by nolasco on 21/07/20.
//

#include <magic_enum/include/magic_enum.hpp>

#include "Factory.h"
#include "libs/random/Random.h"
#include "model/World.h"

namespace model {
ItemId Factory::createEquipment(EquipmentType type) {
  if (type == EquipmentType::UNDEFINED) {
    type = EquipmentType{Random::rand(0, static_cast<Quantity>(EquipmentType::UNDEFINED) - 1)};
  }

  ItemEffect specs = equipmentSpecs(type);
  entity::Equipable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, 1, 3, 5, 50};

  world->equipables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemId Factory::createStaff(StaffType type) {
  if (type == StaffType::UNDEFINED) {
    type = StaffType{Random::rand(0, static_cast<Quantity>(StaffType::UNDEFINED) - 1)};
  }

  ItemEffect specs = staffSpecs(type);
  entity::Equipable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, 1, 2, 10, 25};

  world->equipables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemId Factory::createWeapon(WeaponType type) {
  if (type == WeaponType::UNDEFINED) {
    type = WeaponType{Random::rand(0, static_cast<Quantity>(WeaponType::UNDEFINED) - 1)};
  }

  ItemEffect specs = weaponSpecs(type);
  entity::Equipable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, 1, 10, 25, 50};

  world->equipables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemId Factory::createConsumable(ConsumableType type, const Quantity quantity) {
  if (type == ConsumableType::UNDEFINED) {
    type = ConsumableType{Random::rand(0, static_cast<Quantity>(ConsumableType::UNDEFINED) - 1)};
  }

  ItemEffect specs = consumableSpecs(type);
  entity::Consumable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, quantity, 1, 3, 2};

  world->consumables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemEffect Factory::equipmentSpecs(const EquipmentType type) {
  ItemEffect specs;
  switch (type) {
    case EquipmentType::COAT:
      specs.def = 3;
      specs.ste = 3;
      break;
    case EquipmentType::SHIELD:
      specs.def = 4;
      break;
    case EquipmentType::SKATE:
      specs.spd = 3;
      break;
  }
  return specs;
}

ItemEffect Factory::staffSpecs(const StaffType type) {
  ItemEffect specs;
  switch (type) {
    case StaffType::CONJURING:
      specs.mana = 4;
      break;
    case StaffType::DARK:
      specs.mAtk = 3;
      break;
    case StaffType::SUPPORT:
      specs.mana = 5;
      break;
  }
  specs.ran = 2;
  return specs;
}

ItemEffect Factory::weaponSpecs(const WeaponType type) {
  ItemEffect specs;
  switch (type) {
    case WeaponType::AXE:
      specs.atk = 5;
      specs.ran = 1;
      break;
    case WeaponType::BOW:
      specs.atk = 2;
      specs.ran = 2;
      break;
    case WeaponType::DAGGER:
      specs.atk = 1;
      specs.ran = 1;
      break;
    case WeaponType::KNIFE:
      specs.atk = 1;
      specs.ran = 1;
      break;
    case WeaponType::LONGBOW:
      specs.atk = 2;
      specs.ran = 3;
      break;
    case WeaponType::SWORD:
      specs.atk = 3;
      specs.ran = 1;
      break;
  }
  return specs;
}

ItemEffect Factory::consumableSpecs(const ConsumableType type) {
  ItemEffect specs;
  switch (type) {
    case ConsumableType::COIN:
      break;
    case ConsumableType::ELIXIR:
      specs.hp += 2;
      break;
    case ConsumableType::POISON:
      specs.atk += 3;
      break;
    case ConsumableType::POTION:
      specs.hp += 3;
      break;
  }
  return specs;
}

} // namespace model
