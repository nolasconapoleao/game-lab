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

/// @brief Wrapper for game world manipulation.
class Handler {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param factory game entity creator.
   * @param cleaner game entity destructor.
   * @param lookup game entity finder.
   */
  Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
          const std::shared_ptr<Cleaner> &cleaner, const std::shared_ptr<Lookup> &lookup);

  /// @brief Create world.
  void createWorld();
  /// @brief Destroy world.
  void destroyWorld();

  /**
   * @brief Attack character.
   * @param attackerId attacker id.
   * @param attackedId attacked id.
   * @return attack result.
   */
  AttackResult attackCharacter(CharacterId attackerId, CharacterId attackedId);

  /**
   * @brief Attack structure.
   * @param attackerId attacker id.
   * @param structureId structure id.
   */
  void attackStructure(CharacterId attackerId, StructureId structureId);

  /**
   * @brief Attack building.
   * @param attackerId attacker id.
   * @param buildingId building id.
   */
  void attackBuilding(CharacterId attackerId, LocationId buildingId);

  /**
   * @brief Drop item.
   * @param itemId item id.
   * @param locationId location id.
   * @param quantity to drop.
   */
  void dropItem(ItemId itemId, ResourceId locationId, Quantity quantity = 0);

  /**
   * @brief pickup item.
   * @param characterId chracter id.
   * @param itemId item id.
   * @param quantity to pickup.
   */
  void pickupItem(CharacterId characterId, ItemId itemId, Quantity quantity);

  /**
   * @brief Steal item.
   * @param roberId character id.
   * @param itemId item id.
   */
  void stealItem(CharacterId roberId, ItemId itemId);

  /**
   * @brief Use item.
   * @param itemId item id.
   */
  void useItem(ItemId itemId);

  /**
   * @brief Spend item.
   * @param itemId item id.
   */
  void depleteItem(ItemId itemId);

  /**
   * @brief Spend items in character.
   * @param characterId character id.
   */
  void characterItemDepletion(CharacterId characterId);

  /**
   * @brief Buy item.
   * @param buyerId character id.
   * @param itemId item id.
   * @param quantity to buy.
   */
  void buyItem(CharacterId buyerId, ItemId itemId, Quantity quantity);

  /**
   * @brief Sell item.
   * @param sellerId character id.
   * @param itemId item id.
   * @param quantity to buy.
   */
  void sellItem(CharacterId sellerId, ItemId itemId, Quantity quantity);

  /**
   * @brief Travel to location.
   * @param characterId traveller.
   * @param locationId destination.
   */
  void travel(const CharacterId &characterId, LocationId locationId);

  /**
   * @brief Attempt possession of game character.
   * @param mageId possessor id.
   * @param possessedId possessed id.
   */
  void possess(CharacterId mageId, CharacterId possessedId);

  /**
   * @brief Rename character.
   * @param characterId character id.
   * @param newName new name.
   */
  void renameCharacter(CharacterId characterId, const std::string &newName);

  /**
   * @brief Rename team.
   * @param teamId team id.
   * @param newName new name.
   */
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

  std::shared_ptr<World> mWorld;
  std::shared_ptr<Factory> mFactory;
  std::shared_ptr<Cleaner> mCleaner;
  std::shared_ptr<Lookup> mLookup;
};

} // namespace model
