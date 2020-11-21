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

class Cleaner {
public:
  Cleaner(std::shared_ptr<World> world, std::shared_ptr<Lookup> lookup);
  void deleteCharacter(CharacterId characterId);
  void deleteEquipable(ItemId equipableId);
  void deleteConsumable(ItemId consumableId);
  [[maybe_unused]] void deleteLocation(LocationId locationId);
  void deleteBuilding(LocationId buildingId);
  void deleteStructure(StructureId structureId);

private:
  void cleanupLocation(LocationId locationId);
  std::shared_ptr<World> world;
  std::shared_ptr<Lookup> lookup;
};

} // namespace model
