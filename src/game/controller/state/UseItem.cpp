//
// Created by nolasco on 07/07/20.
//

#include "UseItem.h"

#include "datatypes/state/Substate.h"

namespace controller {

UseItem::UseItem() {
  mCaterpillar.emplace_back(SELECT_ITEM);
  createNetwork();
}

void UseItem::execute() {
  mHandler.updateItem(World::activeCharacter, mInput[SELECT_ITEM]);
}

void UseItem::fillStateOption() {
  view::Printer::addToOptionHeader(Verbose::INFO, "Select Item");
  const auto items = World::itemsOfCharacter(World::activeCharacter);

  for (auto it = 0; it < items.size(); it++) {
    view::Printer::addToOptions(Verbose::INFO, '0' + it, minimalPrint(World::item(it)));
    view::Printer::addToExtraInfo(Verbose::INFO, fullPrint(World::item(it)));
    mOptions += '0' + it;
  }
}

} // namespace controller