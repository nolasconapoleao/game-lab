//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <map>
#include <set>
#include <vector>

#include "datatypes/entity/Building.h"
#include "datatypes/entity/Character.h"
#include "datatypes/entity/Consumable.h"
#include "datatypes/entity/Equipable.h"
#include "datatypes/entity/Exterior.h"
#include "datatypes/entity/Structure.h"
#include "datatypes/entity/Team.h"

namespace model {

class World {
public:
  // Entity storage
  std::map<ResourceId, entity::Character> characters;
  std::map<ResourceId, entity::Consumable> consumables;
  std::map<ResourceId, entity::Equipable> equipables;
  std::map<ResourceId, entity::Exterior> exteriors;
  std::map<ResourceId, entity::Building> buildings;
  std::map<ResourceId, entity::Structure> structures;
  std::map<ResourceId, entity::Team> teams;
  // TODO: Add quests and events

  // Entity relationships
  std::multimap<LocationId, LocationId> neighbours;
  std::map<ItemId, ResourceId> possessions;
  std::map<ResourceId, LocationId> locatedIn;
  std::map<CharacterId, TeamId> memberships;

  // Resource names
  std::vector<std::string> characterNames;
  std::vector<std::string> locationNames;
  std::vector<std::string> teamNames;

  friend class Cleaner;
  friend class Factory;
  friend class Handler;
  friend class Lookup;
};

} // namespace model
