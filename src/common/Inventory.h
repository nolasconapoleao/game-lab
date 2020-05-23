//
// Created by nolasco on 16/05/20.
//

#pragma once

#include <ostream>
#include <vector>

#include "items/Item.h"

struct ConsumableEntry {
  uint8_t itemId;
  Item item;
  uint8_t quantity;
};

struct EquipableEntry {
  uint8_t itemId;
  Item item;
  bool equipped;
};

/**
 * @brief Inventory class has a list of consume and equip items.csv.
 */
class Inventory {
public:
  Inventory();

  void addItem(Item item, uint8_t quantity = 1u);
  bool dropItem(uint8_t itemId, uint8_t quantity = 1u);

  Item &getItem(uint8_t itemId);
  uint8_t totalItems();
  bool useItem(uint8_t itemId);

  friend std::ostream &operator<<(std::ostream &os, const Inventory &inventory);

  /**
   * All items.csv in origin inventory with itemId are sent to destination inventory.
   * @param origin inventory
   * @param destination inventory
   * @param itemId for item to be displaced
   */
  friend void exchangeItem(Inventory &origin, Inventory &destination, uint8_t itemId, uint8_t quantity);

private:
  bool consumeItem(uint8_t itemId);
  bool equipItem(uint8_t itemId);
  bool unequipItem(uint8_t itemId);
  bool toggleEquip(uint8_t itemId);
  std::vector<ConsumableEntry> consumables;
  std::vector<EquipableEntry> equipables;
  uint8_t lastItemId;
};
