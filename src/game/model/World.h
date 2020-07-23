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
#include "datatypes/entity/Equippable.h"
#include "datatypes/entity/Exterior.h"
#include "datatypes/entity/Structure.h"
#include "datatypes/entity/Team.h"

namespace model {

class World {
public:
  // Entity storage
  static std::map<ResourceId, entity::Character> characters;
  static std::map<ResourceId, entity::Consumable> consumables;
  static std::map<ResourceId, entity::Equippable> equippables;
  static std::map<ResourceId, entity::Exterior> exteriors;
  static std::map<ResourceId, entity::Building> buildings;
  static std::map<ResourceId, entity::Structure> structures;
  static std::map<ResourceId, entity::Team> teams;
  // TODO: Add quests and events

  // Entity relationships
  static std::multimap<LocationId, LocationId> neighbours;
  static std::map<ItemId, ResourceId> possessions;
  static std::map<ResourceId, LocationId> locatedIn;
  static std::map<CharacterId, TeamId> memberships;

  // Resource names
  static std::vector<std::string> characterNames;
  static std::vector<std::string> locationNames;
  static std::vector<std::string> teamNames;

  friend class Cleaner;
  friend class Factory;
  friend class Handler;
  friend class Lookup;
};

} // namespace model
