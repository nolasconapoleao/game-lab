//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <memory>
#include <vector>

#include "datatypes/entity/Building.h"
#include "datatypes/entity/Character.h"
#include "datatypes/entity/Consumable.h"
#include "datatypes/entity/Equipable.h"
#include "datatypes/entity/Exterior.h"
#include "datatypes/entity/Structure.h"
#include "datatypes/entity/Team.h"
#include "interface/entity/Item.h"
#include "interface/entity/Location.h"

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
  const std::vector<ItemEntry> &itemsIn(const ResourceId resourceId);
  const std::vector<CharacterEntry> &charactersIn(const LocationId locationId);
  const std::vector<StructureEntry> &structuresIn(const LocationId locationId);
  const std::vector<LocationEntry> &neighbourLocations(const LocationId locationId);
  const std::vector<LocationEntry> &neighboursEndingIn(const LocationId locationId);
  const std::vector<LocationEntry> &neighbourStartingIn(const LocationId locationId);
  std::optional<ItemId> consumableTypeIn(const ResourceId resourceId, const ConsumableType type);

private:
  std::shared_ptr<World> world;
};

} // namespace model
