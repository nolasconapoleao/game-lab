//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "game/model/World.h"
#include "game/model/entity/include/ItemOwnerType.h"
#include "game/view/Printer.h"

class Handler {
public:
  void battle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId);
  void characterGoesTo(const CharacterId &characterId, const LocationId locationId);
  void dropAllItems(const CharacterId characterId, const LocationId locationId);
  void changeItemOwner(ItemId item, const OwnerType &type, const ResourceId newOwner);
  void strategize(const CharacterId characterId);
  void changePlayerName(const CharacterId characterId, const std::string &newName);
  void updateItem(const CharacterId characterId, const ItemId itemId);
  void consumeItem(const ItemId itemId);
  void transferMoney(const CharacterId origin, const CharacterId destination, const Quantity amount);
};