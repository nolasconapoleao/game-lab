//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <memory>
#include <vector>

#include "interface/entity/Item.h"
#include "interface/entity/Location.h"
#include "model/entity/Character.h"
#include "model/entity/Structure.h"

namespace model {

// Forward declaration
class World;

class Lookup {
public:
  Lookup(const std::shared_ptr<World> &world);
  const std::vector<std::pair<ItemId, entity::Item>> &itemsIn(ResourceId id);
  const std::vector<std::pair<CharacterId, entity::Character>> &charactersIn(const LocationId locationId);
  const std::vector<std::pair<StructureId, entity::Structure>> &structuresIn(const LocationId locationId);
  const std::vector<std::pair<LocationId, entity::Location>> &neighbourLocations(LocationId locationId);

private:
  std::shared_ptr<World> world;
};

} // namespace model
