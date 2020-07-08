//
// Created by nolasco on 07/07/20.
//

#include "UseItem.h"

#include "model/state/include/Substate.h"

namespace model::state {

UseItem::UseItem() {
  mCaterpillar.emplace_back(SELECT_ITEM);
  createNetwork();
}

void UseItem::execute() {
  mHandler.updateItem(mWorld.activeCharacter, mInput[SELECT_ITEM]);
}

void UseItem::fillStateOption() {
  mPrinter.addToOptionHeader(Verbose::INFO, "Select Item");
  const auto items = mWorld.itemsOfCharacter(mWorld.activeCharacter);

  for (auto it = 0; it < items.size(); it++) {
    mPrinter.addToOptions(Verbose::INFO, '0' + it, minimalPrint(mWorld.item(it)));
    mPrinter.addToExtraInfo(Verbose::INFO, fullPrint(mWorld.item(it)));
    mOptions += '0' + it;
  }
}

} // namespace model::state