//
// Created by nolasco on 11/06/20.
//

#include "IdleWorld.h"

#include <magic_enum/include/magic_enum.hpp>

#include "game/controller/state/include/Transition.h"

namespace controller {

IdleWorld::IdleWorld() {
  createNetwork();
}

void IdleWorld::fillStateOption() {
  // Intentionally left blank
}

void IdleWorld::execute() {
  World::changeFocusedCharacter();
  // FIXME: Hic sunt dracones - if no character with player ghost exists
  while (GhostInTheShell::Player != World::character(World::activeCharacter).getGhost()) {
    view::Printer::addToRoundReport(Verbose::INFO, "I'm gonna ride this on my own");
    strategize(World::activeCharacter);
    World::changeFocusedCharacter();
  };
  view::Printer::addToRoundReport(Verbose::INFO, "Comand me");
  triggerTransition(TERMINATE);
}

void IdleWorld::strategize(CharacterId characterId) {
  // TODO: use character inteligence, occupation, health, location
  const auto character = World::character(characterId);

  if (character.getStats().hp > 2) {
    const auto result = mHandler.battle(characterId, characterId, World::activeLocation);
    std::string hitReport = character.getName() + " attacks " + character.getName() + ": "
                            + magic_enum::enum_name(AttackResult{result}).data();
    ;
    view::Printer::addToRoundReport(Verbose::INFO, hitReport);
  }
}

} // namespace controller