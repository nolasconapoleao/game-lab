//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <memory>
#include <vector>

#include "interface/entity/Item.h"
#include "interface/entity/Location.h"
#include "model/entity/Building.h"
#include "model/entity/Character.h"
#include "model/entity/Consumable.h"
#include "model/entity/Equipable.h"
#include "model/entity/Exterior.h"
#include "model/entity/Structure.h"
#include "model/entity/Team.h"

struct CharacterEntry {
  CharacterId id;
  std::shared_ptr<entity::Character> entity;
};
struct ItemEntry {
  ItemId id;
  std::shared_ptr<entity::Item> entity;
};
struct LocationEntry {
  LocationId id;
  std::shared_ptr<entity::Location> entity;
};
struct StructureEntry {
  StructureId id;
  std::shared_ptr<entity::Structure> entity;
};
struct TeamEntry {
  TeamId id;
  std::shared_ptr<entity::Team> entity;
};

namespace model {

// Forward declaration
class World;

class Lookup {
public:
  Lookup(const std::shared_ptr<World> &world);
  const std::vector<ItemEntry> &itemsIn(ResourceId resourceId);
  const std::vector<CharacterEntry> &charactersIn(const LocationId locationId);
  const std::vector<StructureEntry> &structuresIn(const LocationId locationId);
  const std::vector<LocationEntry> &neighbourLocations(LocationId locationId);

private:
  std::shared_ptr<World> world;
};

} // namespace model
