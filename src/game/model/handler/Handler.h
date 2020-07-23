//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/factory/ThreatLevel.h"
#include "datatypes/logger/AttackResult.h"
#include "interface/entity/Item.h"
#include "interface/entity/Location.h"

namespace model {

// Forward declaration
class World;
class Factory;
class Cleaner;
class Lookup;

class Handler {
public:
  Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
          const std::shared_ptr<Cleaner> &cleaner, std::shared_ptr<Lookup> lookup);
  void createWorld();
  void destroyWorld();

  AttackResult attackCharacter(const CharacterId attackerId, const CharacterId attackedId);
  void attackStructure(const CharacterId attackerId, const StructureId structureId);
  void attackBuilding(const CharacterId attackerId, const LocationId buildingId);

  void dropItem(const ItemId itemId, const ResourceId locationId, const Quantity quantity = 0);
  void pickupItem(const ItemId itemId, const CharacterId characterId, const Quantity quantity = 0);
  void useItem(const CharacterId characterId, const ItemId itemId);
  void depleteItem(const ItemId itemId);
  void characterItemDepletion(const CharacterId characterId);

  void buyItem(const ItemId itemId, const CharacterId buyerId, Quantity quantity = 0);
  void sellItem(const ItemId itemId, const CharacterId sellerId, Quantity quantity = 0);

  void travel(const CharacterId &characterId, const LocationId locationId);
  void possess(const CharacterId mageId, const CharacterId possessedId);
  void renameCharacter(const CharacterId characterId, const std::string &newName);
  void renameTeam(const TeamId teamId, const std::string &newName);

private:
  void demolishBuilding(const LocationId buildingId);
  void demolishStructure(const StructureId structureId);
  void killCharacter(const CharacterId characterId);
  void destroyItem(ItemId itemId);
  void fillLocation(const LocationId locationId, const ThreatLevel threat);
  void fillInventory(const CharacterId characterId, const ThreatLevel threat);
  void fillExterior(const LocationId locationId, const ThreatLevel threat);
  LocationId createNeighbour(const LocationId locationId, const ThreatLevel threat);

  void transferItem(const ItemId itemId, const ResourceId destinationId, Quantity quantity);
  void stackConsumable(const ItemId itemId, const ResourceId destinationId, Quantity quantity);
  void applyItemEffect(const ItemId itemId);
  void revertItemEffect(const ItemId itemId);
  void transferMoney(const CharacterId originId, const CharacterId destinationId, Number amount);
  Quantity maximumBuyable(const CharacterId characterId, const ItemId itemId);
  int compare(const Quantity attacker, const Quantity defender);

  const std::shared_ptr<entity::Item> &getItem(ItemId itemId);
  const std::shared_ptr<entity::Location> &getLocation(LocationId locationId);

  std::shared_ptr<World> world;
  std::shared_ptr<Factory> factory;
  std::shared_ptr<Cleaner> cleaner;
  std::shared_ptr<Lookup> lookup;
};

} // namespace model
