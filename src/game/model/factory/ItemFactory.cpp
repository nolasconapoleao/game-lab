//
// Created by nolasco on 21/07/20.
//

#include <magic_enum/include/magic_enum.hpp>

#include "Factory.h"
#include "libs/random/Random.h"
#include "model/World.h"

namespace model {
ItemId Factory::createEquipment(EquipmentPrototype type) {
  if (type == EquipmentPrototype::UNDEFINED) {
    type = EquipmentPrototype{Random::rand(0, static_cast<Quantity>(EquipmentPrototype::UNDEFINED) - 1)};
  }

  ItemEffect specs = equipmentSpecs(type);
  entity::Equipable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, 1, 3, 5, 50};

  world->equipables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemId Factory::createStaff(StaffPrototype type) {
  if (type == StaffPrototype::UNDEFINED) {
    type = StaffPrototype{Random::rand(0, static_cast<Quantity>(StaffPrototype::UNDEFINED) - 1)};
  }

  ItemEffect specs = staffSpecs(type);
  entity::Equipable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, 1, 2, 10, 25};

  world->equipables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemId Factory::createWeapon(WeaponPrototype type) {
  if (type == WeaponPrototype::UNDEFINED) {
    type = WeaponPrototype{Random::rand(0, static_cast<Quantity>(WeaponPrototype::UNDEFINED) - 1)};
  }

  ItemEffect specs = weaponSpecs(type);
  entity::Equipable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, 1, 10, 25, 50};

  world->equipables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemId Factory::createConsumable(ConsumablePrototype type, const Quantity quantity) {
  if (type == ConsumablePrototype::UNDEFINED) {
    type = ConsumablePrototype{Random::rand(0, static_cast<Quantity>(ConsumablePrototype::UNDEFINED) - 1)};
  }

  ItemEffect specs = consumableSpecs(type);
  entity::Consumable creation{
      Random::fromVec(world->characterNames) + "'s " + magic_enum::enum_name(type).data(), specs, quantity, 1, 3, 2};

  world->consumables.emplace(entityCounter++, creation);
  return entityCounter;
}

ItemEffect Factory::equipmentSpecs(const EquipmentPrototype type) {
  ItemEffect specs;
  switch (type) {
    case EquipmentPrototype::COAT:
      specs.def += 3;
      specs.ste += 3;
      break;
    case EquipmentPrototype::SHIELD:
      specs.def += 4;
      break;
    case EquipmentPrototype::SKATE:
      specs.spd += 3;
      break;
  }
  return specs;
}

ItemEffect Factory::staffSpecs(const StaffPrototype type) {
  ItemEffect specs;
  switch (type) {
    case StaffPrototype::CONJURING:
      specs.mana += 4;
      break;
    case StaffPrototype::DARK:
      specs.mAtk += 3;
      break;
    case StaffPrototype::SUPPORT:
      specs.mana += 5;
      break;
  }
  return specs;
}

ItemEffect Factory::weaponSpecs(const WeaponPrototype type) {
  ItemEffect specs;
  switch (type) {
    case WeaponPrototype::AXE:
      specs.atk += 5;
      break;
    case WeaponPrototype::BOW:
      specs.atk += 2;
      break;
    case WeaponPrototype::DAGGER:
      specs.atk += 1;
      break;
    case WeaponPrototype::KNIFE:
      specs.atk += 1;
      break;
    case WeaponPrototype::LONGBOW:
      specs.atk += 2;
      break;
    case WeaponPrototype::SWORD:
      specs.atk += 3;
      break;
  }
  return specs;
}

ItemEffect Factory::consumableSpecs(const ConsumablePrototype type) {
  ItemEffect specs;
  switch (type) {
    case ConsumablePrototype::COIN:
      break;
    case ConsumablePrototype::ELIXIR:
      specs.hp += 2;
      break;
    case ConsumablePrototype::POISON:
      specs.atk += 3;
      break;
    case ConsumablePrototype::POTION:
      specs.hp += 3;
      break;
  }
  return specs;
}

} // namespace model
