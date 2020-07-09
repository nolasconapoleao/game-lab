//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "common/GameTypes.h"
#include "model/World.h"
#include "model/entity/include/ItemOwnerType.h"
#include "view/Printer.h"

class Controller {
public:
  void updateViewVariables();
  void battle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId);
  void characterGoesTo(const CharacterId &characterId, const LocationId locationId);
  void dropAllItems(const CharacterId characterId, const LocationId locationId);
  void changeItemOwner(ItemId item, const OwnerType &type, const ResourceId newOwner);
  void strategize(const CharacterId characterId);
  void changePlayerName(const CharacterId characterId, const std::string &newName);
  void updateItem(const CharacterId characterId, const ItemId itemId);
  void consumeItem(const ItemId itemId);
  void transferMoney(const CharacterId origin, const CharacterId destination, const Quantity amount);

private:
  World world;
};
