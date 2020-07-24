//
// Created by nolasco on 21/06/20.
//

#include "StreamConverter.h"

#include <iomanip>
#include <magic_enum/include/magic_enum.hpp>

#include "StreamFormatter.h"

namespace view::stream {

std::ostream &operator<<(std::ostream &os, const Quantity &value) {
  os << std::setw(STAT_LEN) << std::to_string(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Size &value) {
  os << std::right << value.width << "x" << std::left << value.height;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Entity &value) {
  os << std::setw(NAME_LEN) << value.name;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Item &value) {
  os << static_cast<const entity::Entity &>(value) << std::string(ITEM_PADDING, ' ') << value.effect << value.quantity
     << value.unitWeight << value.unitPrice;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Location &value) {
  os << static_cast<const entity::Entity &>(value) << value.size;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Building &value) {
  os << static_cast<const entity::Location &>(value) << value.type << value.health << value.floors;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Exterior &value) {
  os << static_cast<const entity::Location &>(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Character &value) {
  os << static_cast<const entity::Entity &>(value) << value.stats() << value.info << value.effects;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Consumable &value) {
  os << static_cast<const entity::Item &>(value) << value.type << value.duration << value.consumed;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Equippable &value) {
  os << static_cast<const entity::Item &>(value) << value.uses << value.equipped;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Structure &value) {
  os << static_cast<const entity::Entity &>(value) << std::string(2, ' ') << value.health << value.size;
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
  os << std::setw(STAT_LEN) << value.cash << " " << value.ghost << " " << value.race << " " << value.attackType << " "
     << value.occupation;
  return os;
}

std::ostream &operator<<(std::ostream &os, const ItemEffect &value) {
  os << value.hp << value.atk << value.def << value.mAtk << value.mDef << value.spd << value.inte << value.acc
     << value.ste << value.mana << value.ran;
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
  os << static_cast<const ItemEffect &>(value) << value.mhp << value.cst << value.lvl << value.xp;
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
