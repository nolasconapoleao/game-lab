//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <map>
#include <set>

#include "model/entity/Building.h"
#include "model/entity/Character.h"
#include "model/entity/Consumable.h"
#include "model/entity/Equipable.h"
#include "model/entity/Exterior.h"
#include "model/entity/Structure.h"
#include "model/entity/Team.h"

namespace model {

class World {
public:
  // Entity storage
  std::map<ResourceId, entity::Character> characters;
  std::map<ResourceId, entity::Consumable> consumables;
  std::map<ResourceId, entity::Equipable> equipables;
  std::map<ResourceId, entity::Exterior> exteriors;
  std::map<ResourceId, entity::Building> interiors;
  std::map<ResourceId, entity::Structure> structures;
  std::map<ResourceId, entity::Team> teams;

  // Entity relationships
  std::set<std::pair<LocationId, LocationId>> neighbourhoods;
  std::set<std::pair<ResourceId, ItemId>> possessions;
  std::set<std::pair<TeamId, CharacterId>> memberships;

  friend class Cleaner;
  friend class Factory;
  friend class Handler;
  friend class Lookup;
};

} // namespace model
