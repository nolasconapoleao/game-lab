//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"
#include "model/cleaner/Cleaner.h"
#include "model/lookup/Lookup.h"

namespace model {

void Handler::destroyWorld() {
  world->characters.clear();
  world->consumables.clear();
  world->equipables.clear();
  world->exteriors.clear();
  world->buildings.clear();
  world->structures.clear();
  world->teams.clear();

  world->neighbours.clear();
  world->possessions.clear();
  world->locatedIn.clear();
  world->memberships.clear();
}

void Handler::demolishBuilding(const LocationId buildingId) {
  for (auto &character : lookup->charactersIn(buildingId)) {
    killCharacter(character.id);
    cleaner->deleteCharacter(character.id);
  };

  for (auto &item : lookup->itemsIn(buildingId)) {
    transferItem(item.id, world->locatedIn[buildingId], 0);
  };
}

void Handler::demolishStructure(const StructureId structureId) {
  for (auto &item : lookup->itemsIn(structureId)) {
    transferItem(item.id, world->locatedIn[structureId], 0);
  };
}

void Handler::killCharacter(CharacterId characterId) {
  world->characters.find(characterId)->second.effects.emplace(StatusEffect::DEAD);
  for (auto &item : lookup->itemsIn(characterId)) {
    transferItem(item.id, world->locatedIn[characterId], 0);
  };
}

void Handler::destroyItem(ItemId itemId) {
  if (world->consumables.contains(itemId)) {
    cleaner->deleteConsumable(itemId);
  } else if (world->equipables.contains(itemId)) {
    cleaner->deleteEquipable(itemId);
  }
}

} // namespace model
