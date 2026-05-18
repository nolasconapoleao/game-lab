//
// Created by nolasco on 21/06/20.
//

#include "EntityConverter.h"

#include <iomanip>
#include <magic_enum/include/magic_enum.hpp>

#include "GeneralUtilities.h"

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
  os << std::left << std::setw(NAME_LEN) << value.name;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Item &value) {
  os << static_cast<const entity::Entity &>(value) << " Amount:" << value.quantity << std::right << value.unitWeight
     << "Kg " << std::right << value.unitPrice << "$ " << value.effect << " ";
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Location &value) {
  os << static_cast<const entity::Entity &>(value) << " Size:" << value.size;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Building &value) {
  os << static_cast<const entity::Location &>(value) << " Hp:" << value.health << " Floors:" << value.floors;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Exterior &value) {
  os << std::right << std::setw(NAME_LEN) << static_cast<const entity::Location &>(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Character &value) {
  os << static_cast<const entity::Entity &>(value) << value.stats() << value.info << value.effects;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Consumable &value) {
  os << static_cast<const entity::Entity &>(value) << " Amount:" << value.quantity << " Uses:" << value.duration << " "
     << (value.consumed ? '+' : '-') << " " << value.effect;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Equippable &value) {
  os << static_cast<const entity::Entity &>(value) << " Amount:" << value.quantity << " Uses:" << value.uses << " "
     << (value.equipped ? 'I' : 'O') << " " << value.effect;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Structure &value) {
  os << static_cast<const entity::Entity &>(value) << " Hp:" << value.health << " Size:" << value.size;
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

std::ostream &operator<<(std::ostream &os, const EquippableType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Ghost &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Info &value) {
  os << std::right << value.cash << "$ " << value.race << " " << value.occupation;
  return os;
}

std::ostream &operator<<(std::ostream &os, const ItemEffect &value) {
  if (0 != value.hp) {
    os << "Hp:  " << std::left << value.hp;
  }
  if (0 != value.atk) {
    os << "Atk: " << std::left << value.atk;
  }
  if (0 != value.def) {
    os << "Def: " << std::left << value.def;
  }
  if (0 != value.mAtk) {
    os << "MAtk:" << std::left << value.mAtk;
  }
  if (0 != value.mDef) {
    os << "MDef:" << std::left << value.mDef;
  }
  if (0 != value.spd) {
    os << "Spd: " << std::left << value.spd;
  }
  if (0 != value.inte) {
    os << "Inte:" << std::left << value.inte;
  }
  if (0 != value.acc) {
    os << "Acc: " << std::left << value.acc;
  }
  if (0 != value.ste) {
    os << "Ste: " << std::left << value.ste;
  }
  if (0 != value.mana) {
    os << "Mana:" << std::left << value.mana;
  }
  if (0 != value.ran) {
    os << "Ran: " << std::left << value.ran;
  }
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
  os << " Hp:" << std::right << value.hp << "/" << std::left << value.mhp << "Lvl:" << value.lvl;
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
