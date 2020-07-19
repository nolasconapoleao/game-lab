//
// Created by nolasco on 16/06/20.
//

#include "Handler.h"
#include "datatypes/entity/ItemOwnerType.h"
#include "datatypes/entity/ItemOwnership.h"
#include "libs/math/gamemath.h"

void Handler::changeItemOwner(ItemId itemId, const OwnerType &type, ResourceId newOwner) {
  ItemOwnership newOwnership{newOwner, type, false};
  World::item(itemId).setOwnership(newOwnership);
}

void Handler::updateItem(const CharacterId characterId, const ItemId itemId) {
  // TODO: use weight and constitution to check a valid equip
  const auto item = World::item(itemId);
  const auto character = World::character(characterId);
  auto characterTempStats = World::character(characterId).getTempStats();
  auto itemQuantity = World::item(itemId).getQuantity();

  switch (item.getUseType()) {
    case UseType::equip: {
      ItemOwnership updatedOwnership = item.getOwnership();
      updatedOwnership.equipped = !item.getOwnership().equipped;
      World::item(itemId).setOwnership(updatedOwnership);
      updatedOwnership.equipped ? World::character(characterId).setTempStats(characterTempStats + item.getEffect())
                                : World::character(characterId).setTempStats(characterTempStats - item.getEffect());
      break;
    }
    case UseType::singleUse: {
      if (!item.getOwnership().equipped) {
        World::character(characterId).setTempStats(characterTempStats + item.getEffect());
        ItemOwnership updatedOwnership = item.getOwnership();
        updatedOwnership.equipped = true;
        World::item(itemId).setOwnership(updatedOwnership);
        World::item(itemId).setQuantity(itemQuantity - 1);
      }
      consumeItem(itemId);
      break;
    }
  }
}

void Handler::consumeItem(ItemId itemId) {
  auto item = World::item(itemId);
  auto itemQuantity = World::item(itemId).getQuantity();
  World::item(itemId).setQuantity(gamemath::clamp_sub(itemQuantity, 1, 0));
}

void Handler::dropAllItems(const CharacterId characterId, const LocationId locationId) {
  const auto items = World::itemsOfCharacter(characterId);
  for (auto item : items) {
    changeItemOwner(item, OwnerType::LOCATION, locationId);
  }
}

void Handler::dropItem(ItemId itemId, LocationId locationId, Quantity quantity) {
  if (quantity == World::item(itemId).getQuantity()) {
    changeItemOwner(itemId, OwnerType::LOCATION, locationId);
  } else {
    auto itemCopy = World::item(itemId);
    changeItemOwner(itemId, OwnerType::LOCATION, locationId);
    World::item(itemId).setQuantity(itemCopy.getQuantity() - quantity);
    itemCopy.setQuantity(quantity);

    World::addItem(itemCopy);
  }
}
