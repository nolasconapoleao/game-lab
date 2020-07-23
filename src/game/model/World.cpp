//
// Created by nolasco on 23/07/20.
//

#include "World.h"

namespace model {

std::map<ResourceId, entity::Character> World::characters;
std::map<ResourceId, entity::Consumable> World::consumables;
std::map<ResourceId, entity::Equippable> World::equippables;
std::map<ResourceId, entity::Exterior> World::exteriors;
std::map<ResourceId, entity::Building> World::buildings;
std::map<ResourceId, entity::Structure> World::structures;
std::map<ResourceId, entity::Team> World::teams;
std::multimap<LocationId, LocationId> World::neighbours;
std::map<ItemId, ResourceId> World::possessions;
std::map<ResourceId, LocationId> World::locatedIn;
std::map<CharacterId, TeamId> World::memberships;
std::vector<std::string> World::characterNames;
std::vector<std::string> World::locationNames;
std::vector<std::string> World::teamNames;

} // namespace model
