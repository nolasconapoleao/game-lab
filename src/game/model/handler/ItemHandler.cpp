//
// Created by nolasco on 16/06/20.
//

#include "Controller.h"
#include "game/model/entity/include/ItemOwnerType.h"
#include "game/model/entity/include/ItemOwnership.h"
#include "game/model/handler/include/gamemath.h"

void Controller::changeItemOwner(ItemId itemId, const OwnerType &type, ResourceId newOwner) {
  ItemOwnership newOwnership{newOwner, type, false};
  World::item(itemId).setOwnership(newOwnership);
}

void Controller::updateItem(const CharacterId characterId, const ItemId itemId) {
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

void Controller::consumeItem(ItemId itemId) {
  auto item = World::item(itemId);
  auto itemQuantity = World::item(itemId).getQuantity();
  World::item(itemId).setQuantity(gamemath::clamp_sub(itemQuantity, 1, 0));
}

void Controller::dropAllItems(const CharacterId characterId, const LocationId locationId) {
  const auto items = World::itemsOfCharacter(characterId);
  for (auto item : items) {
    changeItemOwner(item, OwnerType::LOCATION, locationId);
  }
}