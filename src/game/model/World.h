//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <queue>
#include <set>

#include "model/entity/Character.h"
#include "model/entity/Consumable.h"
#include "model/entity/Equipable.h"
#include "model/entity/Exterior.h"
#include "model/entity/Interior.h"
#include "model/entity/Structure.h"
#include "model/entity/Team.h"

class World {
public:
  // Active entity
  static void loadNextCharacter();
  static CharacterId activeCharacter;

  // Entity relation
  static void linkLocations(const LocationId begin, const LocationId end);
  static void setItemOwner(const ResourceId owner, const ItemId itemId);
  static void joinTeam(const ResourceId partyId, const CharacterId characterId);

  // Entity management
  static ResourceId addEntity(const std::shared_ptr<entity::Entity> entity);
  static void removeEntity(const ResourceId entityId);
  static std::shared_ptr<entity::Entity> &entity(const ResourceId entityId);
  static std::vector<ResourceId> lookupEntities(const auto searchFunction);

private:
  // Active entity
  static void updateCharacterQueue();
  static std::unordered_set<LocationId> activeLocations();
  static std::priority_queue<std::pair<int, CharacterId>> characterQueue;

  // Entity storage
  static std::map<ResourceId, entity::Character> characters;
  static std::map<ResourceId, entity::Consumable> consumables;
  static std::map<ResourceId, entity::Equipable> equipables;
  static std::map<ResourceId, entity::Exterior> exteriors;
  static std::map<ResourceId, entity::Interior> interiors;
  static std::map<ResourceId, entity::Structure> structures;
  static std::map<ResourceId, entity::Team> teams;

  // Entity relationships
  static std::set<std::pair<LocationId, LocationId>> neighbourhoods;
  static std::set<std::pair<ResourceId, ItemId>> possessions;
  static std::set<std::pair<TeamId, CharacterId>> memberships;

  friend class Cleaner;
  friend class Factory;
  friend class Handler;
  friend class Lookup;
};
