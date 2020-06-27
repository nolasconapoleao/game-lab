//
// Created by nolasco on 24/06/20.
//

#include "Travel.h"

enum STATES : StateId {
  SELECT_DESTINATION = 0,
};

namespace model::state {

Travel::Travel() {
  mCaterpillar.emplace_back(SELECT_DESTINATION);
  createNetwork();
}

void Travel::execute() {
  mHandler.characterGoesTo(mWorld.activeCharacter, mInput[SELECT_DESTINATION]);
}

void Travel::fillStateOption() {
  mPrinter.addToOptionHeader(Verbose::INFO, "Select destination");
  const auto characterLocation = mWorld.character(mWorld.activeCharacter).getLocation();
  const auto neighbours = mWorld.adjcentLocations(characterLocation);

  for (auto it = 0; it < neighbours.size(); it++) {
    mPrinter.addToOptions(Verbose::INFO, '0' + it, minimalPrint(neighbours[it]));
    mOptions += '0' + it;
  }
}

} // namespace model::state
