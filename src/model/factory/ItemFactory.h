//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <vector>

#include "model/entity/Item.h"
#include "model/factory/include/ItemPrototype.h"

class ItemFactory {
public:
  ItemFactory();
  entity::Item generateItem(const UseType useType);
  entity::Item createItem(const ItemPrototype type);

private:
  std::vector<ItemPrototype> equipPool;
  std::vector<ItemPrototype> singleUsePool;
};
