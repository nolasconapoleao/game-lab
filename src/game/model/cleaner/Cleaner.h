//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"

namespace model {

// Forward declaration
class World;
class Lookup;

/// @brief Handles deletion of game entities.
class Cleaner {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param lookup game entity finder.
   */
  Cleaner(std::shared_ptr<World> world, std::shared_ptr<Lookup> lookup);

  /**
   * @brief Delete character.
   * @param characterId character id.
   */
  void deleteCharacter(CharacterId characterId);

  /**
   * @brief Delete equippable.
   * @param equipableId equippable id.
   */
  void deleteEquipable(ItemId equipableId);

  /**
   * @brief Delete consumable.
   * @param consumableId consumable id.
   */
  void deleteConsumable(ItemId consumableId);

  /**
   * @brief Delete location.
   * @param locationId location id.
   */
  [[maybe_unused]] void deleteLocation(LocationId locationId);

  /**
   * @brief Delete building.
   * @param buildingId building id.
   */
  void deleteBuilding(LocationId buildingId);

  /**
   * @brief Delete structure.
   * @param structureId structure id.
   */
  void deleteStructure(StructureId structureId);

private:
  void cleanupLocation(LocationId locationId);
  std::shared_ptr<World> mWorld;
  std::shared_ptr<Lookup> mLookup;
};

} // namespace model
