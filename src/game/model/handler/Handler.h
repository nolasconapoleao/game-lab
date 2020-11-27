//
// Created by nolasco on 20/06/20.
//

#pragma once

#include "interface/model/IHandler.h"

namespace model {

// Forward declaration
class World;
class Factory;
class Cleaner;
class Lookup;

/// @brief Wrapper for game world manipulation.
class Handler : public IHandler {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param factory game entity creator.
   * @param cleaner game entity destructor.
   * @param lookup game entity finder.
   */
  Handler(const std::shared_ptr<World> &world, const std::shared_ptr<IFactory> &factory,
          const std::shared_ptr<ICleaner> &cleaner, const std::shared_ptr<ILookup> &lookup);

  /// @copydoc IHandler::createWorld()
  void createWorld() override;
  /// @copydoc IHandler::destroyWorld()
  void destroyWorld() override;
  /// @copydoc IHandler::attackCharacter()
  AttackResult attackCharacter(CharacterId attackerId, CharacterId attackedId) override;
  /// @copydoc IHandler::attackStructure()
  void attackStructure(CharacterId attackerId, StructureId structureId) override;
  /// @copydoc IHandler::attackBuilding()
  void attackBuilding(CharacterId attackerId, LocationId buildingId) override;
  /// @copydoc IHandler::dropItem()
  void dropItem(ItemId itemId, ResourceId locationId, Quantity quantity = 0) override;
  /// @copydoc IHandler::pickupItem()
  void pickupItem(CharacterId characterId, ItemId itemId, Quantity quantity) override;
  /// @copydoc IHandler::stealItem()
  void stealItem(CharacterId roberId, ItemId itemId) override;
  /// @copydoc IHandler::useItem()
  void useItem(ItemId itemId) override;
  /// @copydoc IHandler::depleteItem()
  void depleteItem(ItemId itemId) override;
  /// @copydoc IHandler::characterItemDepletion()
  void characterItemDepletion(CharacterId characterId) override;
  /// @copydoc IHandler::buyItem()
  void buyItem(CharacterId buyerId, ItemId itemId, Quantity quantity) override;
  /// @copydoc IHandler::sellItem()
  void sellItem(CharacterId sellerId, ItemId itemId, Quantity quantity) override;
  /// @copydoc IHandler::travel()
  void travel(const CharacterId &characterId, LocationId locationId) override;
  /// @copydoc IHandler::possess()
  void possess(CharacterId mageId, CharacterId possessedId) override;
  /// @copydoc IHandler::renameCharacter()
  void renameCharacter(CharacterId characterId, const std::string &newName) override;
  /// @copydoc IHandler::renameTeam()
  void renameTeam(TeamId teamId, const std::string &newName) override;

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
  std::shared_ptr<IFactory> mFactory;
  std::shared_ptr<ICleaner> mCleaner;
  std::shared_ptr<ILookup> mLookup;
};

} // namespace model
