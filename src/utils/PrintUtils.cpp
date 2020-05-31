//
// Created by nolasco on 16/05/20.
//

#include "PrintUtils.h"

#include <magic_enum.hpp>
#include <sstream>

std::ostream &operator<<(std::ostream &os, const uint8_t &number) {
  return os << std::to_string(number);
}

std::ostream &operator<<(std::ostream &os, const Effect &effect) {
  os << magic_enum::enum_name(effect);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
  os << item.name << " affects " << item.effect << " by " << item.modifierValue;
  return os;
}

std::string printPocket(const Entry &entry) {
  std::ostringstream os;
  os << "Use (";
  os << ((UseType::consume == entry.item.useType) ? std::to_string(entry.quantity) : (entry.inUse ? "e" : "u"));
  os << "): " << entry.item;
  if (UseType::equip == entry.item.useType) {
    os << " - (" << entry.item.duration << " uses left)";
  }
  return os.str().data();
}

std::string printFloor(const Entry &entry) {
  std::ostringstream os;
  os << "Pickup ";
  if (UseType::consume == entry.item.useType) {
    os << "(" << entry.quantity << ") ";
  }
  os << entry.item.name;
  return os.str().data();
}

std::string printShop(const Entry &entry) {
  std::ostringstream os;
  os << "Buy " << entry.item.name << " costs " << entry.item.price << "$";
  return os.str().data();
}

std::ostream &operator<<(std::ostream &os, const Character &character) {
  os << character.name << "\tHP: " << character.properties.health << "/" << character.properties.maxHealth;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
  os << room.description << std::endl;
  os << "\tNpcs:";
  for (const auto &npc : room.npcs) {
    os << std::endl << "\t" << npc;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const UseType &useType) {
  os << magic_enum::enum_name(useType);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Diplomacy &diplomacy) {
  os << magic_enum::enum_name(diplomacy);
  return os;
}

std::ostream &operator<<(std::ostream &os, const AttackResult &room) {
  os << magic_enum::enum_name(room);
  return os;
}

std::string printPlayer(const Character &player) {
  std::ostringstream os;
  os << player;
  os << "\tAtk: " << player.properties.attack;
  os << "\tDef: " << player.properties.defense;
  os << "\tSpeed: " << player.properties.speed << std::endl;
  os << "\t\tMoney: " << player.properties.money;
  os << "\tLvl: " << player.properties.level;
  os << "\tXp: " << player.properties.experience << std::endl;
  return os.str();
}

std::ostream &operator<<(std::ostream &os, const OptionList &list) {
  for (uint8_t i = 0; i < list.options.size(); i++) {
    os << char(list.options[i].first) << ": " << list.options[i].second << std::endl;
  }
  return os;
}
