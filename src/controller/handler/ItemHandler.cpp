//
// Created by nolasco on 16/06/20.
//

#include "Controller.h"
#include "model/entity/include/ItemOwnerType.h"
#include "model/entity/include/ItemOwnership.h"

void Controller::changeItemOwner(ItemId itemId, const OwnerType &type, ResourceId newOwner) {
  ItemOwnership newOwnership{newOwner, type, false};
  world.item(itemId).setOwnership(newOwnership);
}
