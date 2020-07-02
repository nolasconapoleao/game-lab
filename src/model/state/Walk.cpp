//
// Created by nolasco on 24/06/20.
//

#include "Walk.h"

enum STATES : StateId {
  SELECT_DESTINATION = 0,
};

namespace model::state {

Walk::Walk() {
  mCaterpillar.emplace_back(SELECT_DESTINATION);
  createNetwork();
}

void Walk::execute() {
  mHandler.characterGoesTo(mWorld.activeCharacter, mInput[SELECT_DESTINATION]);
}

void Walk::fillStateOption() {
  mPrinter.addToOptionHeader(Verbose::INFO, "Select destination");
  const auto characterLocation = mWorld.character(mWorld.activeCharacter).getLocation();
  const auto neighbours = mWorld.adjcentLocations(characterLocation);

  for (auto it = 0; it < neighbours.size(); it++) {
    mPrinter.addToOptions(Verbose::INFO, '0' + it, minimalPrint(mWorld.location(it)));
    mOptions += '0' + it;
  }
}

} // namespace model::state
