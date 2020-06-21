//
// Created by nolasco on 20/06/20.
//

#include "EntityHandler.h"

#include "view/include/StreamConverter.h"

void EntityHandler::updateViewVariables() {
  mPrinter.resetLists();

  const auto characters = charactersInLocation(0);
  for (const auto character : characters) {
    mPrinter.addToHud(Verbose::INFO, view::toString(character));
  }
}

void EntityHandler::attack(entity::Character &attacker, entity::Character &attacked) {
  combatHandler.handleAttack(attacker, attacked);
}

std::vector<entity::Item> EntityHandler::itemsOfCharacter(CharacterId characterId) {
  std::vector<entity::Item> result;
  auto saveItem = [characterId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::CHARACTER) && (item.getOwnership().resourceId == characterId)) {
      result.emplace_back(item);
    };
  };
  std::for_each(world.items.begin(), world.items.end(), saveItem);
  return result;
}

std::vector<entity::Item> EntityHandler::itemsInLocation(CharacterId locationId) {
  std::vector<entity::Item> result;
  auto saveItem = [locationId, &result](entity::Item item) {
    if ((item.getOwnership().ownerType == OwnerType::LOCATION) && (item.getOwnership().resourceId == locationId)) {
      result.emplace_back(item);
    };
  };
  std::for_each(world.items.begin(), world.items.end(), saveItem);
  return result;
}

std::vector<entity::Character> EntityHandler::charactersInLocation(LocationId locationId) {
  std::vector<entity::Character> result;
  auto saveCharacter = [locationId, &result](entity::Character character) {
    if (character.getLocation() == locationId) {
      result.emplace_back(character);
    };
  };
  std::for_each(world.characters.begin(), world.characters.end(), saveCharacter);
  return result;
}

std::vector<entity::Structure> EntityHandler::structuresInLocation(LocationId locationId) {
  std::vector<entity::Structure> result;
  auto saveStructure = [locationId, &result](entity::Structure structure) {
    if (structure.getLocation() == locationId) {
      result.emplace_back(structure);
    };
  };
  std::for_each(world.structures.begin(), world.structures.end(), saveStructure);
  return result;
}

std::vector<entity::Location> EntityHandler::adjcentLocations(LocationId locationId) {
  auto neighbours = world.worldMap.neighbours(locationId);
  std::vector<entity::Location> result;

  for (const auto locationId : neighbours) {
    result.emplace_back(world.worldMap.location(locationId));
  }

  return result;
}
