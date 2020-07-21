//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/logger/AttackResult.h"

namespace model {

// Forward declaration
class World;
class Factory;
class Cleaner;

class Handler {
public:
  void createWorld();
  void destroyWorld();

  AttackResult attackCharacter(const CharacterId attackerId, const CharacterId attackedId);
  void attackStructure(const CharacterId attackerId, const StructureId structureId);
  void attackBuilding(const CharacterId attackerId, const LocationId inLocationId);

  void dropItem(const ItemId itemId, const ResourceId locationId, const Quantity quantity = 0);
  void pickupItem(const ItemId itemId, const CharacterId characterId, const Quantity quantity = 0);
  void useItem(const CharacterId characterId, const ItemId itemId);

  void buyItem(const ItemId itemId, const CharacterId characterId, const Quantity quantity = 0);
  void sellItem(const ItemId itemId, const CharacterId characterId, const Quantity quantity = 0);

  void travel(const CharacterId &characterId, const LocationId locationId);

  void possessCharacter(const CharacterId mageId, const CharacterId possessedId);

private:
  void fillLocation(LocationId locationId);
  void fillInventory(CharacterId characterId);

  void transferItem(const ItemId itemId, const ResourceId locationId, const Quantity quantity = 0);
  void transferMoney(const CharacterId origin, const CharacterId destination, const Quantity quantity = 0);
  std::shared_ptr<World> world;
  std::shared_ptr<Factory> factory;
  std::shared_ptr<Cleaner> cleaner;
};

} // namespace model
