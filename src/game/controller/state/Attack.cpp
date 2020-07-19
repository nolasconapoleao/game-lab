//
// Created by nolasco on 29/06/20.
//

#include "Attack.h"

#include "datatypes/state/Substate.h"
#include "view/cases/Logger.h"

namespace controller {

Attack::Attack() {
  mCaterpillar.emplace_back(SELECT_CHARACTER);
  createNetwork();
}

void Attack::execute() {
  const auto result = mHandler.battle(World::activeCharacter, mInput[SELECT_CHARACTER], World::activeLocation);
  logBattle(World::activeCharacter, mInput[SELECT_CHARACTER], World::activeLocation, result);
}

void Attack::fillStateOption() {
  view::Printer::addToOptionHeader(Verbose::INFO, "Select character");
  const auto characterLocation = World::character(World::activeCharacter).getLocation();
  const auto characters = World::charactersInLocation(characterLocation);

  for (auto it = 0; it < characters.size(); it++) {
    view::Printer::addToOptions(Verbose::INFO, '0' + it, minimalPrint(World::character(it)));
    mOptions += '0' + it;
  }
}

} // namespace controller
