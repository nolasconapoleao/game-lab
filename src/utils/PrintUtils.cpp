//
// Created by nolasco on 16/05/20.
//

#include "PrintUtils.h"

#include <game/OptionList.h>
#include <magic_enum.hpp>

std::ostream &operator<<(std::ostream &os, const uint8_t &number) {
  return os << std::to_string(number);
}

std::ostream &operator<<(std::ostream &os, const Effect &effect) {
  os << magic_enum::enum_name(effect);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
  os << item.name << " affects " << item.modifier << " by " << item.modifierValue;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Inventory &inventory) {
  for (const auto &consumableEntry : inventory.consumables) {
    os << "(" << consumableEntry.quantity << "): " << consumableEntry.item.name << " - "
       << consumableEntry.item.description << std::endl;
  }
  for (const auto &equipableEntry : inventory.equipables) {
    os << "(" << (equipableEntry.equipped ? "e" : "u") << "): " << equipableEntry.item.name << " - "
       << equipableEntry.item.description << std::endl;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const Character &character) {
  os << character.name << " HP: " << character.properties.health << "/" << character.properties.maxHealth;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Room &room) {
  os << room.description << std::endl;
  for (const auto &npc : room.npcs) {
    os << npc << std::endl;
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

std::ostream &operator<<(std::ostream &os, const OptionList &list) {
  for (uint8_t i = 0; i < list.options.size(); i++) {
    os << char(list.options[i].first) << ": " << list.options[i].second << std::endl;
  }
  return os;
}
