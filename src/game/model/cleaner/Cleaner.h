//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "interface/model/ICleaner.h"

namespace model {

// Forward declaration
class World;
class Lookup;

/// @brief Handles deletion of game entities.
class Cleaner : public ICleaner {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param lookup game entity finder.
   */
  Cleaner(std::shared_ptr<World> world, std::shared_ptr<ILookup> lookup);

  /// @copydoc ICleaner::deleteCharacter()
  void deleteCharacter(CharacterId characterId);
  /// @copydoc ICleaner::deleteEquipable()
  void deleteEquipable(ItemId equipableId);
  /// @copydoc ICleaner::deleteConsumable()
  void deleteConsumable(ItemId consumableId);
  /// @copydoc ICleaner::deleteLocation()
  [[maybe_unused]] void deleteLocation(LocationId locationId);
  /// @copydoc ICleaner::deleteBuilding()
  void deleteBuilding(LocationId buildingId);
  /// @copydoc ICleaner::deleteStructure()
  void deleteStructure(StructureId structureId);

private:
  void cleanupLocation(LocationId locationId);
  std::shared_ptr<World> mWorld;
  std::shared_ptr<ILookup> mLookup;
};

} // namespace model
