//
// Created by nolasco on 19/05/20.
//

#include "Shop.h"

Shop::Shop() : BaseRoom("Shop", "Shop has a shopkeeper") {
  npcs.push_back(std::make_shared<Shopkeeper>(shopkeeper));
}
