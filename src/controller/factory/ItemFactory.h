//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <vector>

#include "controller/factory/include/ItemPrototype.h"
#include "model/entity/Item.h"

class ItemFactory {
public:
  ItemFactory();
  entity::Item generateItem(const UseType useType);
  entity::Item createItem(const ItemPrototype type);

private:
  std::vector<ItemPrototype> equipPool;
  std::vector<ItemPrototype> singleUsePool;
};
