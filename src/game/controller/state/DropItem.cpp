//
// Created by nolasco on 18/07/20.
//

#include "DropItem.h"

#include "controller/input/Input.h"
#include "datatypes/state/Substate.h"
#include "view/entity/StreamConverter.h"

namespace controller {

DropItem::DropItem() {
  mCaterpillar.emplace_back(SELECT_ITEM);
  mCaterpillar.emplace_back(SELECT_QUANTITY);
  createNetwork();
}

void DropItem::execute() {
  mHandler.transferItem(mInput[SELECT_ITEM], World::activeLocation, mInput[SELECT_QUANTITY]);
}

void DropItem::fillStateOption() {
  switch (mActiveState) {
    case SELECT_ITEM: {
      view::Printer::addToOptionHeader(Verbose::INFO, "Select Item");
      const auto items = World::itemsOfCharacter(World::activeCharacter);

      for (auto it = 0; it < items.size(); it++) {
        view::Printer::addToOptions(Verbose::INFO, '0' + it, minimalPrint(World::item(it)));
        view::Printer::addToExtraInfo(Verbose::INFO, fullPrint(World::item(it)));
        mOptions += '0' + it;
      }
    } break;
    case SELECT_QUANTITY: {

      const auto max = World::item(mInput[SELECT_ITEM]).getQuantity();
      if (World::item(mInput[SELECT_ITEM]).getUseType() == UseType::equip) {
        mInput[SELECT_QUANTITY] = max;
        return;
      }
      view::Printer::addToExtraInfo(Verbose::INFO, fullPrint(World::item(mInput[SELECT_ITEM])));
      view::Printer::addToOptionHeader(Verbose::INFO, "How many? No more than " + std::to_string(max));
      view::Printer::printScreen();
      mInput[SELECT_QUANTITY] = input::readNum(0, max);
    } break;
  }
}

} // namespace controller