//
// Created by nolasco on 16/06/20.
//

#include "ItemHandler.h"

void ItemHandler::changeItemOwner(entity::Item &item, const OwnerType &type, ResourceId newOwner) {
  ItemOwnership newOwnership{newOwner, type, false};
  item.setOwnership(newOwnership);
}
