//
// Created by nolasco on 21/06/20.
//

#include "StreamConverter.h"

#include <iomanip>
#include <magic_enum/include/magic_enum.hpp>

namespace view::stream {

std::ostream &operator<<(std::ostream &os, const Quantity &value) {
  os << std::setw(3) << std::to_string(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Size &value) {
  os << value.width << "x" << value.height;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Entity &value) {
  os << value.name;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Item &value) {
  os << static_cast<const entity::Entity &>(value) << " effect: " << value.effect << " quantity: " << value.quantity
     << " unitWeight: " << value.unitWeight << " unitPrice: " << value.unitPrice;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Location &value) {
  os << static_cast<const entity::Entity &>(value) << " size: " << value.size;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Building &value) {
  os << static_cast<const entity::Location &>(value) << " type: " << value.type << " health: " << value.health
     << " floors: " << value.floors;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Character &value) {
  os << static_cast<const entity::Entity &>(value) << " base: " << value.base << " temp: " << value.temp
     << " info: " << value.info << " effects: " << value.effects;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Consumable &value) {
  os << static_cast<const entity::Item &>(value) << " type: " << value.type << " duration: " << value.duration
     << " consumed: " << value.consumed;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Equippable &value) {
  os << static_cast<const entity::Item &>(value) << " uses: " << value.uses << " equipped: " << value.equipped;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Structure &value) {
  os << static_cast<const entity::Entity &>(value) << " type: " << value.type << " health: " << value.health
     << " size: " << value.size;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Team &value) {
  os << static_cast<const entity::Entity &>(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const AttackType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const BuildingType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const ConsumableType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Ghost &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Info &value) {
  os << "cash: " << value.cash << " ghost: " << value.ghost << " race: " << value.race
     << " attackType: " << value.attackType << " occupation: " << value.occupation;
  return os;
}

std::ostream &operator<<(std::ostream &os, const ItemEffect &value) {
  os << "hp: " << value.hp << " atk: " << value.atk << " def: " << value.def << " mAtk: " << value.mAtk
     << " mDef: " << value.mDef << " spd: " << value.spd << " inte: " << value.inte << " acc: " << value.acc
     << " ste: " << value.ste << " mana: " << value.mana << " ran: " << value.ran;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Occupation &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Race &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Stats &value) {
  os << static_cast<const ItemEffect &>(value) << " mhp: " << value.mhp << " cst: " << value.cst
     << " lvl: " << value.lvl << " xp: " << value.xp;
  return os;
}

std::ostream &operator<<(std::ostream &os, const StatusEffect &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const StructureType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

} // namespace view::stream
