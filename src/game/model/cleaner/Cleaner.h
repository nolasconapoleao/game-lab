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
  Cleaner(const std::shared_ptr<World> &world, std::shared_ptr<Lookup> lookup);
  void deleteCharacter(const CharacterId characterId);
  void deleteEquipable(const ItemId equipableId);
  void deleteConsumable(const ItemId consumableId);
  [[maybe_unused]] void deleteLocation(const LocationId locationId);
  void deleteBuilding(const LocationId buildingId);
  void deleteStructure(const StructureId structureId);

private:
  void cleanupLocation(const LocationId locationId);
  std::shared_ptr<World> world;
  std::shared_ptr<Lookup> lookup;
};

} // namespace model
