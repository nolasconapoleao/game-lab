//
// Created by nolasco on 16/06/20.
//

#include "Controller.h"
#include "controller/handler/include/gamemath.h"
#include "model/entity/include/ItemOwnerType.h"
#include "model/entity/include/ItemOwnership.h"

void Controller::changeItemOwner(ItemId itemId, const OwnerType &type, ResourceId newOwner) {
  ItemOwnership newOwnership{newOwner, type, false};
  world.item(itemId).setOwnership(newOwnership);
}

void Controller::updateItem(const CharacterId characterId, const ItemId itemId) {
  // TODO: use weight and constitution to check a valid equip
  const auto item = world.item(itemId);
  const auto character = world.character(characterId);
  auto characterTempStats = world.character(characterId).getTempStats();
  auto itemQuantity = world.item(itemId).getQuantity();

  switch (item.getUseType()) {
    case UseType::equip: {
      ItemOwnership updatedOwnership = item.getOwnership();
      updatedOwnership.equipped = !item.getOwnership().equipped;
      world.item(itemId).setOwnership(updatedOwnership);
      updatedOwnership.equipped ? world.character(characterId).setTempStats(characterTempStats + item.getEffect())
                                : world.character(characterId).setTempStats(characterTempStats - item.getEffect());
      break;
    }
    case UseType::singleUse: {
      if (!item.getOwnership().equipped) {
        world.character(characterId).setTempStats(characterTempStats + item.getEffect());
        ItemOwnership updatedOwnership = item.getOwnership();
        updatedOwnership.equipped = true;
        world.item(itemId).setOwnership(updatedOwnership);
        world.item(itemId).setQuantity(itemQuantity - 1);
      }
      consumeItem(itemId);
      break;
    }
  }
}

void Controller::consumeItem(ItemId itemId) {
  auto item = world.item(itemId);
  auto itemQuantity = world.item(itemId).getQuantity();
  world.item(itemId).setQuantity(gamemath::clamp_sub(itemQuantity, 1, 0));
}

void Controller::dropAllItems(const CharacterId characterId, const LocationId locationId) {
  const auto items = world.itemsOfCharacter(characterId);
  for (auto item : items) {
    changeItemOwner(item, OwnerType::LOCATION, locationId);
  }
}