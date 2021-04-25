//
// Created by nolasco on 08/12/20.
//

#pragma once

#include "GameConstant.h"
#include "model/World.h"

namespace testHelper {
Snapshot createSnapshotMock() {
  return Snapshot{characterEntry,    locationEntry,    {consumablesEntry}, {equipablesEntry}, {characterEntry},
                  {structuresEntry}, {buildingsEntry}, {exteriorsEntry},   {floorEntry},      ownedByEntry};
}

} // namespace testHelper
