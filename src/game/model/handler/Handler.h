//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/factory/ThreatLevel.h"
#include "datatypes/logger/AttackResult.h"

namespace model {

// Forward declaration
class World;
class Factory;
class Cleaner;

class Handler {
public:
  Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
          const std::shared_ptr<Cleaner> &cleaner);
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
  void possess(CharacterId mageId, CharacterId possessedId);
  void renameCharacter(CharacterId characterId, const std::string &newName);
  void renameTeam(TeamId teamId, const std::string &newName);

private:
  void demolishBuilding(const LocationId buildingId);
  void demolishStructure(const StructureId structureId);
  void fillLocation(const LocationId locationId, const ThreatLevel threat);
  void fillInventory(const CharacterId characterId, const ThreatLevel threat);

  void transferItem(const ItemId itemId, const ResourceId locationId, const Quantity quantity = 0);
  void transferMoney(const CharacterId origin, const CharacterId destination, const Quantity quantity = 0);
  Quantity compare(const Quantity attacker, const Quantity defender);
  std::shared_ptr<World> world;
  std::shared_ptr<Factory> factory;
  std::shared_ptr<Cleaner> cleaner;
};

} // namespace model
