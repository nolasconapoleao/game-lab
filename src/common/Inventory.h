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

class Inventory {
public:
  Inventory();

  void addItem(std::shared_ptr<BaseItem> item);
  bool dropItem(uint itemId);

  bool consumeItem(uint itemId);

  bool equipItem(uint itemId);
  bool unequipItem(uint itemId);

  friend std::ostream &operator<<(std::ostream &os, const Inventory &inventory);

private:
  std::vector<ConsumableEntry> consumables;
  std::vector<EquipableEntry> equipables;
  uint lastItemId;
};
