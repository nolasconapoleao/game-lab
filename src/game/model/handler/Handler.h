//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/factory/CreationSpecs.h"
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
          const std::shared_ptr<Cleaner> &cleaner, const std::shared_ptr<Lookup> &lookup);
  void createWorld();
  void destroyWorld();

  AttackResult attackCharacter(CharacterId attackerId, CharacterId attackedId);
  void attackStructure(CharacterId attackerId, StructureId structureId);
  void attackBuilding(CharacterId attackerId, LocationId buildingId);

  void dropItem(ItemId itemId, ResourceId locationId, Quantity quantity = 0);
  void pickupItem(CharacterId characterId, ItemId itemId, Quantity quantity);
  void stealItem(CharacterId roberId, ItemId itemId);
  void useItem(ItemId itemId);
  void depleteItem(ItemId itemId);
  void characterItemDepletion(CharacterId characterId);

  void buyItem(CharacterId buyerId, ItemId itemId, Quantity quantity);
  void sellItem(CharacterId sellerId, ItemId itemId, Quantity quantity);

  void travel(const CharacterId &characterId, LocationId locationId);
  void possess(CharacterId mageId, CharacterId possessedId);
  void renameCharacter(CharacterId characterId, const std::string &newName);
  void renameTeam(TeamId teamId, const std::string &newName);

private:
  LocationId createGroundZero();
  LocationId createNeighbour(LocationId locationId, ThreatLevel threat);
  void fillLocation(LocationId locationId, ThreatLevel threat);
  void fillInventory(CharacterId characterId, ThreatLevel threat);
  void fillFloor(ResourceId locationId, ThreatLevel threat);
  void fillExterior(LocationId locationId, ThreatLevel threat);

  void demolishBuilding(LocationId buildingId);
  void demolishStructure(StructureId structureId);
  void killCharacter(CharacterId characterId);
  void destroyItem(ItemId itemId);

  void transferItem(ItemId itemId, ResourceId destinationId, Quantity quantity);
  void stackConsumable(ItemId itemId, ResourceId destinationId, Quantity quantity);
  void applyItemEffect(ItemId itemId);
  void revertItemEffect(ItemId itemId);
  void transferMoney(CharacterId originId, CharacterId destinationId, Number amount);
  Quantity maximumBuyable(CharacterId characterId, ItemId itemId);
  static int compare(Quantity attacker, Quantity defender);

  std::shared_ptr<World> world;
  std::shared_ptr<Factory> factory;
  std::shared_ptr<Cleaner> cleaner;
  std::shared_ptr<Lookup> lookup;
};

} // namespace model
