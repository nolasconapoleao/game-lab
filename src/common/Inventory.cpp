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
        = std::find_if(items.begin(), items.end(), [item](Entry entry) { return item.name == entry.item.name; });

    if (it == items.end()) {
      items.emplace_back(Entry{item, false, quantity});
    } else {
      it->quantity += quantity;
    }
  } else if (UseType::equip == item.useType) {
    items.emplace_back(Entry{item, false, quantity});
  }
}

void Inventory::dropItem(uint8_t itemId, uint8_t subtrahend) {
  auto entry = items.begin() + itemId;
  entry->quantity = MathUtils::clamp_sub(entry->quantity, subtrahend, 0);
  if (entry->quantity == 0) {
    items.erase(items.begin() + itemId);
  }
}

void Inventory::useItem(uint8_t itemId) {
  const auto entry = items.begin() + itemId;
  if (entry->item.useType == UseType::consume) {
    dropItem(itemId, 1);
  } else if (entry->item.useType == UseType::equip) {
    toggleEquip(itemId);
  }
}

bool Inventory::toggleEquip(uint8_t itemId) {
  const auto entryInList = items.begin() + itemId;

  if (entryInList->inUse) {
    entryInList->inUse = false;
  } else {
    const auto findItem = std::find_if(items.begin(), items.end(), [entryInList](Entry entry) {
      return (entryInList->item.effect == entry.item.effect && entry.inUse);
    });

    entryInList->inUse = (findItem != items.end());
  }
}

Item &Inventory::getItem(uint8_t itemId) {
  return (items.begin() + itemId)->item;
}

uint8_t Inventory::totalItems() {
  return items.size();
}
