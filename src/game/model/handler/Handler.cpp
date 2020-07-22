//
// Created by nolasco on 21/07/20.
//

#include "Handler.h"

#include "model/World.h"

namespace model {

Handler::Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
                 const std::shared_ptr<Cleaner> &cleaner, std::shared_ptr<Lookup> lookup)
    : world(world), factory(factory), cleaner(cleaner), lookup(lookup) {
}

void Handler::travel(const CharacterId &characterId, const LocationId locationId) {
  world->locatedIn[characterId] = locationId;
}

void Handler::possess(const CharacterId mageId, const CharacterId possessedId) {
  const auto mage = world->characters.find(mageId)->second;
  const auto possessed = world->characters.find(possessedId)->second;
  if (compare(mage.stats().mAtk, possessed.stats().mDef)) {
    world->characters.find(possessedId)->second.info.ghost = Ghost::PLAYER;
  }
}

const std::shared_ptr<entity::Item> Handler::getItem(ItemId itemId) {
  if (world->consumables.contains(itemId)) {
    return std::make_shared<entity::Consumable>(world->consumables.find(itemId)->second);
  } else if (world->equipables.contains(itemId)) {
    return std::make_shared<entity::Equipable>(world->equipables.find(itemId)->second);
  }
}

const std::shared_ptr<entity::Location> Handler::getLocation(LocationId locationId) {
  if (world->exteriors.contains(locationId)) {
    return std::make_shared<entity::Exterior>(world->exteriors.find(locationId)->second);
  } else if (world->buildings.contains(locationId)) {
    return std::make_shared<entity::Building>(world->buildings.find(locationId)->second);
  }
}

} // namespace model
