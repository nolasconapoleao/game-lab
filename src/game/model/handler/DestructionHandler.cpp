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
  world->equippables.clear();
  world->exteriors.clear();
  world->buildings.clear();
  world->structures.clear();
  world->teams.clear();

  world->neighbours.clear();
  world->locatedIn.clear();
  world->locatedIn.clear();
  world->memberships.clear();
}

void Handler::demolishBuilding(const LocationId buildingId) {
  for (const auto &character : lookup->charactersIn(buildingId)) {
    killCharacter(character.id);
  };

  for (const auto &item : lookup->itemsIn(buildingId)) {
    transferItem(item.id, world->locatedIn[buildingId], 0);
  };

  for (const auto &structure : lookup->structuresIn(buildingId)) {
    demolishStructure(structure.id);
  };
  cleaner->deleteBuilding(buildingId);
}

void Handler::demolishStructure(const StructureId structureId) {
  for (const auto &item : lookup->itemsIn(structureId)) {
    transferItem(item.id, world->locatedIn[structureId], 0);
  };
  cleaner->deleteStructure(structureId);
}

void Handler::killCharacter(CharacterId characterId) {
  world->characters.find(characterId)->second.effects.emplace(StatusEffect::DEAD);
  for (const auto &item : lookup->itemsIn(characterId)) {
    transferItem(item.id, world->locatedIn[characterId], 0);
  };
  cleaner->deleteCharacter(characterId);
}

void Handler::destroyItem(ItemId itemId) {
  if (CONSUMABLE == lookup->type(itemId)) {
    cleaner->deleteConsumable(itemId);
  } else if (EQUIPPABLE == lookup->type(itemId)) {
    cleaner->deleteEquipable(itemId);
  }
}

} // namespace model
