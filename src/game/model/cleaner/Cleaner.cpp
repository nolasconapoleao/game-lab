//
// Created by nolasco on 21/07/20.
//

#include "Cleaner.h"

#include <utility>

#include "model/World.h"
#include "model/lookup/Lookup.h"

namespace model {

Cleaner::Cleaner(std::shared_ptr<World> world, std::shared_ptr<Lookup> lookup)
    : mWorld(std::move(world)), mLookup(std::move(lookup)) {
}

void Cleaner::deleteCharacter(const CharacterId characterId) {
  mWorld->characters.erase(characterId);
  mWorld->locatedIn.erase(characterId);
  mWorld->memberships.erase(characterId);
  for (const auto &itemEntry : mLookup->itemsIn(characterId)) {
    mWorld->locatedIn.erase(itemEntry.id);
  }
}

void Cleaner::deleteEquipable(const ItemId equipableId) {
  mWorld->equippables.erase(equipableId);
  mWorld->locatedIn.erase(equipableId);
}

void Cleaner::deleteConsumable(const ItemId consumableId) {
  mWorld->consumables.erase(consumableId);
  mWorld->locatedIn.erase(consumableId);
}

[[maybe_unused]] void Cleaner::deleteLocation(const LocationId locationId) {
  cleanupLocation(locationId);
  mWorld->exteriors.erase(locationId);
}

void Cleaner::deleteBuilding(const LocationId buildingId) {
  cleanupLocation(buildingId);
  mWorld->locatedIn.erase(buildingId);
  mWorld->buildings.erase(buildingId);
}

void Cleaner::deleteStructure(const StructureId structureId) {
  for (const auto &itemEntry : mLookup->itemsIn(structureId)) {
    mWorld->locatedIn.erase(itemEntry.id);
  }
  mWorld->locatedIn.erase(structureId);
  mWorld->structures.erase(structureId);
}

void Cleaner::cleanupLocation(const LocationId locationId) {
  for (const auto &itemEntry : mLookup->itemsIn(locationId)) {
    mWorld->locatedIn.erase(itemEntry.id);
  }

  for (const auto &characterEntry : mLookup->charactersIn(locationId)) {
    mWorld->locatedIn.erase(characterEntry.id);
  }

  for (const auto &structureEntry : mLookup->structuresIn(locationId)) {
    mWorld->locatedIn.erase(structureEntry.id);
  }

  mWorld->neighbours.erase(locationId);
  for (const auto &locationEntry : mLookup->neighboursEndingIn(locationId)) {
    mWorld->neighbours.erase(locationEntry.id);
  }
}

} // namespace model
