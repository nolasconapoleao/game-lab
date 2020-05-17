//
// Created by nolasco on 16/05/20.
//

#include <characters/BaseCharacter.h>
#include <rooms/BaseRoom.h>

#include "common/Inventory.h"
#include "items/BaseItem.h"

std::ostream &operator<<(std::ostream &os, const CharacterProperty &property) {
  switch (property) {
  case CharacterProperty::maxHealth:
    os << "Max health";
    break;
  case CharacterProperty::currentHealth:
    os << "Current health";
    break;
  case CharacterProperty::attack:
    os << "Attack";
    break;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const BaseItem &item) {
  os << item.name << "affects " << item.modifier << " by " << item.modifierValue << std::endl;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Inventory &inventory) {
  for (const auto &consumableEntry : inventory.consumables) {
    os << consumableEntry.itemId << " (" << consumableEntry.quantity << "): " << consumableEntry.item->name
       << std::endl;
  }
  for (const auto &equipableEntry : inventory.equipables) {
    os << equipableEntry.itemId << " (" << (equipableEntry.equipped ? "e" : "u") << "): " << equipableEntry.item->name
       << std::endl;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const BaseCharacter &character) {
  os << character.name << " HP: " << character.currentHealthPoints << "/" << character.maxHealthPoints;
  return os;
}

std::ostream &operator<<(std::ostream &os, const BaseRoom &room) {
  os << room.description << std::endl;
  for (const auto &npc : room.npcs) {
    os << *npc.get() << std::endl;
  }
  return os;
}