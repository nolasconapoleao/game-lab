//
// Created by nolasco on 16/05/20.
//

#include "Inventory.h"

#include <algorithm>

Inventory::Inventory() {
  lastItemId = 1;
}

void Inventory::addItem(std::shared_ptr<BaseItem> item) {
  if (UseType::consumable == item->useType) {
    const auto &it = std::find_if(consumables.begin(), consumables.end(),
                                  [item](ConsumableEntry entry) { return item->name == entry.item->name; });

    if (it == consumables.end()) {
      consumables.emplace_back(ConsumableEntry{lastItemId, item, 1});
      lastItemId++;
    } else {
      it->quantity++;
    }
  } else if (UseType::equipable == item->useType) {
    equipables.emplace_back(EquipableEntry{lastItemId, item, false});
    lastItemId++;
  }
}

bool Inventory::dropItem(uint itemId) {
  auto existsInInventory =
      std::find_if(consumables.begin(), consumables.end(),
                   [itemId](ConsumableEntry entry) { return itemId == entry.itemId; }) != consumables.end() ||
      std::find_if(equipables.begin(), equipables.end(),
                   [itemId](EquipableEntry entry) { return itemId == entry.itemId; }) != equipables.end();

  consumables.erase(std::remove_if(consumables.begin(), consumables.end(),
                                   [itemId](ConsumableEntry entry) { return itemId == entry.itemId; }),
                    consumables.end());

  equipables.erase(std::remove_if(equipables.begin(), equipables.end(),
                                  [itemId](EquipableEntry entry) { return itemId == entry.itemId; }),
                   equipables.end());

  return existsInInventory;
}

bool Inventory::consumeItem(uint itemId) {
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

bool Inventory::equipItem(uint itemId) {
  const auto it = std::find_if(equipables.begin(), equipables.end(),
                               [itemId](EquipableEntry entry) { return itemId == entry.itemId; });

  if (it == equipables.end()) {
    // TODO: Add logging for error case
    return false;
  }

  const auto itemAlreadyEquipped = std::find_if(equipables.begin(), equipables.end(), [it](EquipableEntry entry) {
    return (it->item->modifier == entry.item->modifier && entry.equipped);
  });

  it->equipped = (itemAlreadyEquipped == equipables.end());
  return it->equipped;
}

bool Inventory::unequipItem(uint itemId) {
  const auto it = std::find_if(equipables.begin(), equipables.end(),
                               [itemId](EquipableEntry entry) { return itemId == entry.itemId; });

  if (it == equipables.end()) {
    // TODO: Add logging for error case
    return false;
  }

  it->equipped = false;
  return true;
}
