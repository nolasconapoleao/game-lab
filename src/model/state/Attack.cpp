//
// Created by nolasco on 29/06/20.
//

#include "Attack.h"

#include "model/state/include/Substate.h"

namespace model::state {

Attack::Attack() {
  mCaterpillar.emplace_back(SELECT_CHARACTER);
  createNetwork();
}

void Attack::execute() {
  mHandler.battle(mWorld.activeCharacter, mInput[SELECT_CHARACTER], mWorld.activeLocation);
}

void Attack::fillStateOption() {
  view::Printer::addToOptionHeader(Verbose::INFO, "Select character");
  const auto characterLocation = mWorld.character(mWorld.activeCharacter).getLocation();
  const auto characters = mWorld.charactersInLocation(characterLocation);

  for (auto it = 0; it < characters.size(); it++) {
    view::Printer::addToOptions(Verbose::INFO, '0' + it, minimalPrint(mWorld.character(it)));
    mOptions += '0' + it;
  }
}

} // namespace model::state
