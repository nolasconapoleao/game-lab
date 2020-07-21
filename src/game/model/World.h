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
  std::vector<std::string> idleTalk;

  friend class Cleaner;
  friend class Factory;
  friend class Handler;
  friend class Lookup;
};

} // namespace model
