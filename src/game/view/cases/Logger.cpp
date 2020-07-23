//
// Created by nolasco on 16/07/20.
//

#include "Logger.h"

#include <magic_enum/include/magic_enum.hpp>

#include "model/World.h"
#include "view/Printer.h"

void logBattle(CharacterId attackerId, CharacterId attackedId, LocationId battleGroundId, AttackResult result) {
  std::string hitReport = World::character(attackerId).getName() + " attacks " + World::character(attackedId).getName()
                          + ": " + magic_enum::enum_name(AttackResult{result}).data();
  view::Printer::addToRoundReport(Verbose::INFO, hitReport);
}

std::string printScene() {
  std::ostringstream os;
  os << "Characters:";
  for (const auto characterId : World::charactersInLocation(World::activeLocation)) {
    os << " " << minimalPrint(World::character(characterId));
  }

  os << "\nStructures:";
  for (const auto structureId : World::structuresInLocation(World::activeLocation)) {
    os << " " << minimalPrint(World::structure(structureId));
  }

  os << "\nItems:";
  for (const auto itemId : World::itemsInLocation(World::activeLocation)) {
    os << " " << minimalPrint(World::item(itemId));
  }

  os << "\nNeighbourhood:";
  for (const auto locationId : World::adjcentLocations(World::activeLocation)) {
    os << " " << minimalPrint(World::location(locationId));
  }

  return os.str();
}