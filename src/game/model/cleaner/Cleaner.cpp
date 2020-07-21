//
// Created by nolasco on 21/07/20.
//

#include "Cleaner.h"

#include "model/World.h"
#include "model/lookup/Lookup.h"

namespace model {

Cleaner::Cleaner(const std::shared_ptr<World> &world, std::shared_ptr<Lookup> lookup) : world(world), lookup(lookup) {
}

void Cleaner::deleteCharacter(CharacterId characterId) {
  world->characters.erase(characterId);
  for (auto itemEntry : lookup->itemsIn(characterId)) {
    world->possessions.erase(itemEntry.id);
  }
}

void Cleaner::deleteEquipable(ItemId equipableId) {
  world->equipables.erase(equipableId);
}

void Cleaner::deleteConsumable(ItemId consumableId) {
  world->consumables.erase(consumableId);
}

void Cleaner::deleteLocation(LocationId locationId) {
  world->exteriors.erase(locationId);
  cleanupLocation(locationId);
}

void Cleaner::deleteBuilding(LocationId buildingId) {
  world->buildings.erase(buildingId);
  cleanupLocation(buildingId);
}

void Cleaner::deleteStructure(StructureId structureId) {
  world->structures.erase(structureId);
  for (auto itemEntry : lookup->itemsIn(structureId)) {
    world->possessions.erase(itemEntry.id);
  }
}

void Cleaner::cleanupLocation(LocationId locationId) {
  for (auto itemEntry : lookup->itemsIn(locationId)) {
    world->possessions.erase(itemEntry.id);
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
