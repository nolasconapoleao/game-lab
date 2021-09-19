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
class IFactory;
class ICleaner;
class ILookup;

/// @brief Interface for wrapper for game world manipulation.
class IHandler {
public:
  /// @brief Default constructor.
  IHandler() = default;

  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param factory game entity creator.
   * @param cleaner game entity destructor.
   * @param lookup game entity finder.
   */
  IHandler(const std::shared_ptr<World> &world, const std::shared_ptr<IFactory> &factory,
           const std::shared_ptr<ICleaner> &cleaner, const std::shared_ptr<ILookup> &lookup)
      : mWorld(world)
      , mFactory(factory)
      , mCleaner(cleaner)
      , mLookup(lookup){};

  /// @brief Create world.
  virtual void createWorld() = 0;
  /// @brief Destroy world.
  virtual void destroyWorld() = 0;

  /**
   * @brief Attack character.
   * @param attackerId attacker id.
   * @param attackedId attacked id.
   * @return attack result.
   */
  virtual AttackResult attackCharacter(CharacterId attackerId, CharacterId attackedId) = 0;

  /**
   * @brief Attack structure.
   * @param attackerId attacker id.
   * @param structureId structure id.
   */
  virtual void attackStructure(CharacterId attackerId, StructureId structureId) = 0;

  /**
   * @brief Attack building.
   * @param attackerId attacker id.
   * @param buildingId building id.
   */
  virtual void attackBuilding(CharacterId attackerId, LocationId buildingId) = 0;

  /**
   * @brief Drop item.
   * @param itemId item id.
   * @param locationId location id.
   * @param quantity to drop.
   */
  virtual void dropItem(ItemId itemId, ResourceId locationId, Quantity quantity = 0) = 0;

  /**
   * @brief pickup item.
   * @param characterId chracter id.
   * @param itemId item id.
   * @param quantity to pickup.
   */
  virtual void pickupItem(CharacterId characterId, ItemId itemId, Quantity quantity) = 0;

  /**
   * @brief Steal item.
   * @param roberId character id.
   * @param itemId item id.
   */
  virtual void stealItem(CharacterId roberId, ItemId itemId) = 0;

  /**
   * @brief Use item.
   * @param itemId item id.
   */
  virtual void useItem(ItemId itemId) = 0;

  /**
   * @brief Spend item.
   * @param itemId item id.
   */
  virtual void depleteItem(ItemId itemId) = 0;

  /**
   * @brief Spend items in character.
   * @param characterId character id.
   */
  virtual void characterItemDepletion(CharacterId characterId) = 0;

  /**
   * @brief Buy item.
   * @param buyerId character id.
   * @param itemId item id.
   * @param quantity to buy.
   */
  virtual void buyItem(CharacterId buyerId, ItemId itemId, Quantity quantity) = 0;

  /**
   * @brief Sell item.
   * @param sellerId character id.
   * @param itemId item id.
   * @param quantity to buy.
   */
  virtual void sellItem(CharacterId sellerId, ItemId itemId, Quantity quantity) = 0;

  /**
   * @brief Travel to location.
   * @param characterId traveller.
   * @param locationId destination.
   */
  virtual void travel(const CharacterId &characterId, LocationId locationId) = 0;

  /**
   * @brief Attempt possession of game character.
   * @param mageId possessor id.
   * @param possessedId possessed id.
   */
  virtual void possess(CharacterId mageId, CharacterId possessedId) = 0;

  /**
   * @brief Rename character.
   * @param characterId character id.
   * @param newName new name.
   */
  virtual void renameCharacter(CharacterId characterId, const std::string &newName) = 0;

  /**
   * @brief Rename team.
   * @param teamId team id.
   * @param newName new name.
   */
  virtual void renameTeam(TeamId teamId, const std::string &newName) = 0;

protected:
  /// @brief Database of game entities.
  std::shared_ptr<World> mWorld;
  /// @brief Instance to create game instances.
  std::shared_ptr<IFactory> mFactory;
  /// @brief Instance to destry game instances.
  std::shared_ptr<ICleaner> mCleaner;
  /// @brief Instance to look for game instances.
  std::shared_ptr<ILookup> mLookup;
};

} // namespace model
