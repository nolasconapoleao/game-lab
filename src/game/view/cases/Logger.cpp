//
// Created by nolasco on 16/07/20.
//

#include "Logger.h"

#include <magic_enum/include/magic_enum.hpp>

#include "game/model/World.h"
#include "game/view/Printer.h"

void logBattle(CharacterId attackerId, CharacterId attackedId, LocationId battleGroundId, AttackResult result) {
  std::string hitReport = World::character(attackerId).getName() + " attacks " + World::character(attackedId).getName()
                          + ": " + magic_enum::enum_name(AttackResult{result}).data();
  view::Printer::addToRoundReport(Verbose::INFO, hitReport);
}
