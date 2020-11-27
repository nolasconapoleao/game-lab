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
  // TODO: protected member variable not recognized in the scope of derived class
  std::shared_ptr<World> mWorld;
  std::shared_ptr<ILookup> mLookup;
};

} // namespace model
