//
// Created by nolasco on 16/05/20.
//

#pragma once

#include <memory>
#include <ostream>
#include <vector>

#include "items/BaseItem.h"

struct ConsumableEntry {
  uint itemId;
  std::shared_ptr<BaseItem> item;
  uint quantity;
};

struct EquipableEntry {
  uint itemId;
  std::shared_ptr<BaseItem> item;
  bool equipped;
};

/**
 * @brief Inventory class has a list of consumable and equipable items.csv.
 */
class Inventory {
public:
  Inventory();

  void addItem(std::shared_ptr<BaseItem> item, uint quantity = 1u);
  bool dropItem(uint itemId, uint quantity = 1u);

  std::shared_ptr<BaseItem> getItem(uint itemId);
  uint totalItems();
  bool useItem(uint itemId);

  friend std::ostream &operator<<(std::ostream &os, const Inventory &inventory);

  /**
   * All items.csv in origin inventory with itemId are sent to destination inventory.
   * @param origin inventory
   * @param destination inventory
   * @param itemId for item to be displaced
   */
  friend void exchangeItem(Inventory &origin, Inventory &destination, uint itemId, uint quantity);

private:
  bool consumeItem(uint itemId);
  bool equipItem(uint itemId);
  bool unequipItem(uint itemId);
  bool toggleEquip(uint itemId);
  std::vector<ConsumableEntry> consumables;
  std::vector<EquipableEntry> equipables;
  uint lastItemId;
};
