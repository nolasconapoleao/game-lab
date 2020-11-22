//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"
#include "model/cleaner/Cleaner.h"
#include "model/lookup/Lookup.h"

namespace model {

void Handler::destroyWorld() {
  mWorld->characters.clear();
  mWorld->consumables.clear();
  mWorld->equippables.clear();
  mWorld->exteriors.clear();
  mWorld->buildings.clear();
  mWorld->structures.clear();
  mWorld->teams.clear();

  mWorld->neighbours.clear();
  mWorld->locatedIn.clear();
  mWorld->locatedIn.clear();
  mWorld->memberships.clear();
}

void Handler::demolishBuilding(const LocationId buildingId) {
  for (const auto &character : mLookup->charactersIn(buildingId)) {
    killCharacter(character.id);
  };

  for (const auto &item : mLookup->itemsIn(buildingId)) {
    transferItem(item.id, mWorld->locatedIn[buildingId], 0);
  };

  for (const auto &structure : mLookup->structuresIn(buildingId)) {
    demolishStructure(structure.id);
  };
  mCleaner->deleteBuilding(buildingId);
}

void Handler::demolishStructure(const StructureId structureId) {
  for (const auto &item : mLookup->itemsIn(structureId)) {
    transferItem(item.id, mWorld->locatedIn[structureId], 0);
  };
  mCleaner->deleteStructure(structureId);
}

void Handler::killCharacter(CharacterId characterId) {
  mWorld->characters.find(characterId)->second.effects.emplace(StatusEffect::DEAD);
  for (const auto &item : mLookup->itemsIn(characterId)) {
    transferItem(item.id, mWorld->locatedIn[characterId], 0);
  };
  mCleaner->deleteCharacter(characterId);
}

void Handler::destroyItem(ItemId itemId) {
  if (CONSUMABLE == mLookup->type(itemId)) {
    mCleaner->deleteConsumable(itemId);
  } else if (EQUIPPABLE == mLookup->type(itemId)) {
    mCleaner->deleteEquipable(itemId);
  }
}

} // namespace model
