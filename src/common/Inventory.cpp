//
// Created by nolasco on 16/05/20.
//

#include "Inventory.h"

#include <algorithm>
#include <utils/MathUtils.h>

Inventory::Inventory() {
}

void Inventory::addItem(Item item, uint8_t quantity) {
  if (UseType::consume == item.useType) {
    const auto &it
        = std::find_if(entries.begin(), entries.end(), [item](Entry entry) { return item.name == entry.item.name; });

    if (it == entries.end()) {
      entries.emplace_back(Entry{item, false, quantity});
    } else {
      it->quantity += quantity;
    }
  } else if (UseType::equip == item.useType) {
    entries.emplace_back(Entry{item, false, quantity});
  }
}

void Inventory::dropItem(uint8_t itemId, uint8_t subtrahend) {
  auto entry = entries.begin() + itemId;
  entry->quantity = MathUtils::clamp_sub(entry->quantity, subtrahend, 0);
  if (entry->quantity == 0) {
    entries.erase(entries.begin() + itemId);
  }
}

void Inventory::useItem(uint8_t itemId) {
  const auto entry = entries.begin() + itemId;
  if (entry->item.useType == UseType::consume) {
    dropItem(itemId, 1);
  } else if (entry->item.useType == UseType::equip) {
    toggleEquip(itemId);
  }
}

bool Inventory::toggleEquip(uint8_t itemId) {
  const auto entryInList = entries.begin() + itemId;

  if (entryInList->inUse) {
    entryInList->inUse = false;
  } else {
    const auto findItem = std::find_if(entries.begin(), entries.end(), [entryInList](Entry entry) {
      return (entryInList->item.effect == entry.item.effect && entry.inUse);
    });

    entryInList->inUse = (findItem == entries.end());
  }
}

Item &Inventory::getItem(uint8_t itemId) {
  return (entries.begin() + itemId)->item;
}
