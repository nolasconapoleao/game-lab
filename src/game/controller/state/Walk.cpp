//
// Created by nolasco on 24/06/20.
//

#include "Walk.h"

#include "game/controller/state/include/Substate.h"

namespace controller {

Walk::Walk() {
  mCaterpillar.emplace_back(SELECT_LOCATION);
  createNetwork();
}

void Walk::execute() {
  mHandler.characterGoesTo(World::activeCharacter, mInput[SELECT_LOCATION]);
}

void Walk::fillStateOption() {
  view::Printer::addToOptionHeader(Verbose::INFO, "Select destination");
  const auto characterLocation = World::character(World::activeCharacter).getLocation();
  const auto neighbours = World::adjcentLocations(characterLocation);

  for (auto it = 0; it < neighbours.size(); it++) {
    view::Printer::addToOptions(Verbose::INFO, '0' + it, minimalPrint(World::location(it)));
    mOptions += '0' + it;
  }
}

} // namespace controller
