//
// Created by nolasco on 20/06/20.
//

#include "EntityHandler.h"

std::vector<entity::Item> EntityHandler::itemsOfCharacter(CharacterId characterId) {
  std::vector<entity::Item> result;
  auto saveItem = [characterId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::CHARACTER) && (item.getOwnership().resourceId == characterId)) {
      result.emplace_back(item);
    };
  };
  std::for_each(world.items.begin(), world.items.end(), saveItem);
  return result;
}
