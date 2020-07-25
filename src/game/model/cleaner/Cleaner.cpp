//
// Created by nolasco on 21/07/20.
//

#include "Cleaner.h"

#include "model/World.h"
#include "model/lookup/Lookup.h"

namespace model {

Cleaner::Cleaner(const std::shared_ptr<World> &world, std::shared_ptr<Lookup> lookup)
    : world(std::move(world)), lookup(std::move(lookup)) {
}

void Cleaner::deleteCharacter(const CharacterId characterId) {
  world->characters.erase(characterId);
  world->locatedIn.erase(characterId);
  world->memberships.erase(characterId);
  for (auto itemEntry : lookup->itemsIn(characterId)) {
    world->locatedIn.erase(itemEntry.id);
  }
}

void Cleaner::deleteEquipable(const ItemId equipableId) {
  world->equippables.erase(equipableId);
  world->locatedIn.erase(equipableId);
}

void Cleaner::deleteConsumable(const ItemId consumableId) {
  world->consumables.erase(consumableId);
  world->locatedIn.erase(consumableId);
}

void Cleaner::deleteLocation(const LocationId locationId) {
  cleanupLocation(locationId);
  world->exteriors.erase(locationId);
}

void Cleaner::deleteBuilding(const LocationId buildingId) {
  cleanupLocation(buildingId);
  world->buildings.erase(buildingId);
}

void Cleaner::deleteStructure(const StructureId structureId) {
  for (auto itemEntry : lookup->itemsIn(structureId)) {
    world->locatedIn.erase(itemEntry.id);
  }
  world->structures.erase(structureId);
}

void Cleaner::cleanupLocation(const LocationId locationId) {
  for (auto itemEntry : lookup->itemsIn(locationId)) {
    world->locatedIn.erase(itemEntry.id);
  }

  for (auto characterEntry : lookup->charactersIn(locationId)) {
    world->locatedIn.erase(characterEntry.id);
  }

  for (auto structureEntry : lookup->structuresIn(locationId)) {
    world->locatedIn.erase(structureEntry.id);
  }

  world->neighbours.erase(locationId);
  for (auto locationEntry : lookup->neighboursEndingIn(locationId)) {
    world->neighbours.erase(locationEntry.id);
  }
}

} // namespace model
