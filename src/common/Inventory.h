//
// Created by nolasco on 16/05/20.
//

#pragma once

#include <ostream>
#include <vector>

#include "items/Item.h"

struct Entry {
  Item item;
  bool inUse = false;
  uint8_t quantity;
};

/**
 * @brief Inventory class has a list of items.
 */
class Inventory {
public:
  Inventory();

  void addItem(Item item, uint8_t quantity = 1u);
  void dropItem(uint8_t itemId, uint8_t subtrahend = 1u);

  Item &getItem(uint8_t itemId);
  uint8_t totalItems();
  void useItem(uint8_t itemId);

  friend std::ostream &operator<<(std::ostream &os, const Inventory &inventory);

  /**
   * All items in origin inventory with itemId are sent to destination inventory.
   * @param origin inventory
   * @param destination inventory
   * @param itemId for item to be displaced
   */
  friend void exchangeItem(Inventory &origin, Inventory &destination, uint8_t itemId, uint8_t quantity);

private:
  bool toggleEquip(uint8_t itemId);
  std::vector<Entry> items;
};
