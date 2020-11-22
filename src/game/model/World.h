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

/// @brief Full state of game entities.
class World {
public:
  // Entity storage
  /// @brief Characters in world.
  std::map<ResourceId, entity::Character> characters;
  /// @brief Consumables in world.
  std::map<ResourceId, entity::Consumable> consumables;
  /// @brief Equippables in world.
  std::map<ResourceId, entity::Equippable> equippables;
  /// @brief Exteriors in world.
  std::map<ResourceId, entity::Exterior> exteriors;
  /// @brief Buildings in world.
  std::map<ResourceId, entity::Building> buildings;
  /// @brief Structures in world.
  std::map<ResourceId, entity::Structure> structures;
  /// @brief Teams in world.
  std::map<ResourceId, entity::Team> teams;
  // TODO: Add quests and events

  // Entity relationships
  /// @brief Neighbourhood location network.
  std::multimap<LocationId, LocationId> neighbours;
  /// @brief Location of game entities.
  std::map<ResourceId, ResourceId> locatedIn;
  /// @brief Team memberships of characters.
  std::map<CharacterId, TeamId> memberships;

  // Resource names
  /// @brief Character mames.
  std::vector<std::string> characterNames;
  /// @brief Location names.
  std::vector<std::string> locationNames;
  /// @brief Team names.
  std::vector<std::string> teamNames;

  /// @brief game entity remover.
  friend class Cleaner;
  /// @brief game entity creator.
  friend class Factory;
  /// @brief game entity controller.
  friend class Handler;
  /// @brief game entity finder.
  friend class Lookup;
};

} // namespace model
