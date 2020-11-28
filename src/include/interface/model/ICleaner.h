//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"

namespace model {

// Forward declaration
class World;
class ILookup;

/// @brief Interface for handler deletion of game entities.
class ICleaner {
public:
  /// @brief Default constructor.
  ICleaner() = default;

  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param lookup game entity finder.
   */
  ICleaner(const std::shared_ptr<World> &world, const std::shared_ptr<ILookup> &lookup)
      : mWorld(std::move(world)), mLookup(std::move(lookup)){};

  /**
   * @brief Delete character.
   * @param characterId character id.
   */
  virtual void deleteCharacter(CharacterId characterId) = 0;

  /**
   * @brief Delete equippable.
   * @param equipableId equippable id.
   */
  virtual void deleteEquipable(ItemId equipableId) = 0;

  /**
   * @brief Delete consumable.
   * @param consumableId consumable id.
   */
  virtual void deleteConsumable(ItemId consumableId) = 0;

  /**
   * @brief Delete location.
   * @param locationId location id.
   */
  virtual void deleteLocation(LocationId locationId) = 0;

  /**
   * @brief Delete building.
   * @param buildingId building id.
   */
  virtual void deleteBuilding(LocationId buildingId) = 0;

  /**
   * @brief Delete structure.
   * @param structureId structure id.
   */
  virtual void deleteStructure(StructureId structureId) = 0;

protected:
  std::shared_ptr<World> mWorld;
  std::shared_ptr<ILookup> mLookup;
};

} // namespace model
