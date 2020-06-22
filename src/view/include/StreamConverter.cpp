//
// Created by nolasco on 21/06/20.
//

#include "StreamConverter.h"

#include <magic_enum/include/magic_enum.hpp>
#include <sstream>

std::ostream &operator<<(std::ostream &os, const Quantity &value) {
  os << std::to_string(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Race &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const GhostInTheShell &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const CharacterAttack &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Occupation &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Passport &value) {
  os << "faction: " << value.faction << " party: " << value.party << " occupation: " << value.occupation
     << " race: " << value.race << " characterAttack: " << value.characterAttack;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::Stats &value) {
  os << " mhp: " << value.mhp << " cst: " << value.cst << " lvl: " << value.lvl << " xp: " << value.xp
     << " cash: " << value.cash;
  return os;
}

std::ostream &operator<<(std::ostream &os, const entity::ItemEffect &value) {
  os << " atk: " << value.atk << " def: " << value.def << " spd: " << value.spd << " hp: " << value.hp;
  return os;
}

std::string entity::minimalPrint(const entity::Character &character) {
  std::ostringstream os;
  os << character.name << " " << character.baseStats.mhp << "/" << (character.baseStats.hp + character.tempStats.hp);
  return os.str();
}

std::string entity::fullPrint(const entity::Character &character) {
  std::ostringstream os;
  os << "name: " << character.name << " baseStats: " << character.baseStats << " tempStats: " << character.tempStats
     << " ghost: " << character.ghost << " passport: " << character.passport;
  return os.str();
}