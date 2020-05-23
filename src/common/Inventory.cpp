//
// Created by nolasco on 16/05/20.
//

#include "Inventory.h"

#include <algorithm>

Inventory::Inventory() {
  lastItemId = 1;
}

void Inventory::addItem(Item item, uint8_t quantity) {
  if (UseType::consumable == item.useType) {
    const auto &it = std::find_if(consumables.begin(), consumables.end(),
                                  [item](ConsumableEntry entry) { return item.name == entry.item.name; });

    if (it == consumables.end()) {
      consumables.emplace_back(ConsumableEntry{lastItemId, item, quantity});
      lastItemId++;
    } else {
      it->quantity += quantity;
    }
  } else if (UseType::equipable == item.useType) {
    equipables.emplace_back(EquipableEntry{lastItemId, item, false});
    lastItemId++;
  }
}

bool Inventory::dropItem(uint8_t itemId, uint8_t quantity) {
  bool existsInInventory;
  auto consumableEntry = std::find_if(consumables.begin(), consumables.end(),
                                      [itemId](ConsumableEntry entry) { return itemId == entry.itemId; });
  if (consumableEntry != consumables.end()) {
    existsInInventory = true;
    consumables.erase(std::remove_if(consumables.begin(), consumables.end(),
                                     [itemId](ConsumableEntry entry) { return itemId == entry.itemId; }),
                      consumables.end());
  }

  auto equipableEntry = std::find_if(equipables.begin(), equipables.end(),
                                     [itemId](EquipableEntry entry) { return itemId == entry.itemId; });
  if (equipableEntry != equipables.end()) {
    existsInInventory = true;
    equipables.erase(std::remove_if(equipables.begin(), equipables.end(),
                                    [itemId](EquipableEntry entry) { return itemId == entry.itemId; }),
                     equipables.end());
  }

  return existsInInventory;
}

bool Inventory::consumeItem(uint8_t itemId) {
  const auto it = std::find_if(consumables.begin(), consumables.end(),
                               [itemId](ConsumableEntry entry) { return itemId == entry.itemId; });

  if (it == consumables.end()) {
    // TODO: Add logging for error case:
    // https://github.com/gabime/spdlog
    return false;
  }

  it->quantity--;
  if (it->quantity == 0) {
    dropItem(itemId);
  }
  return true;
}

bool Inventory::equipItem(uint8_t itemId) {
  const auto it = std::find_if(equipables.begin(), equipables.end(),
                               [itemId](EquipableEntry entry) { return itemId == entry.itemId; });

  if (it == equipables.end()) {
    // TODO: Add logging for error case
    return false;
  }

  const auto itemAlreadyEquipped = std::find_if(equipables.begin(), equipables.end(), [it](EquipableEntry entry) {
    return (it->item.modifier == entry.item.modifier && entry.equipped);
  });

  it->equipped = (itemAlreadyEquipped == equipables.end());
  return it->equipped;
}

bool Inventory::unequipItem(uint8_t itemId) {
  const auto it = std::find_if(equipables.begin(), equipables.end(),
                               [itemId](EquipableEntry entry) { return itemId == entry.itemId; });

  if (it == equipables.end()) {
    // TODO: Add logging for error case
    return false;
  }

  it->equipped = false;
  return true;
}

bool Inventory::useItem(uint8_t itemId) {
  const auto item = getItem(itemId);
  if (item.useType == UseType::consumable) {
    consumeItem(itemId);
  } else if (item.useType == UseType::equipable) {
    toggleEquip(itemId);
  }
}

bool Inventory::toggleEquip(uint8_t itemId) {
  const auto entry = std::find_if(equipables.begin(), equipables.end(),
                                  [itemId](EquipableEntry entry) { return itemId == entry.itemId; });
  return entry->equipped ? unequipItem(itemId) : equipItem(itemId);
}

Item &Inventory::getItem(uint8_t itemId) {
  const auto consumableEntry = std::find_if(consumables.begin(), consumables.end(),
                                            [itemId](ConsumableEntry entry) { return itemId == entry.itemId; });
  if (consumableEntry != consumables.end()) {
    return consumableEntry->item;
  }

  const auto equipableEntry = std::find_if(equipables.begin(), equipables.end(),
                                           [itemId](EquipableEntry entry) { return itemId == entry.itemId; });
  if (equipableEntry != equipables.end()) {
    return equipableEntry->item;
  }
}

uint8_t Inventory::totalItems() {
  return consumables.size() + equipables.size();
}
