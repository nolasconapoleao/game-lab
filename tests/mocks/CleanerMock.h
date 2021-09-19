//
// Created by nolasco on 27/11/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "interface/model/ICleaner.h"

class CleanerMock : public trompeloeil::mock_interface<model::ICleaner> {
  IMPLEMENT_MOCK1(deleteCharacter);
  IMPLEMENT_MOCK1(deleteEquipable);
  IMPLEMENT_MOCK1(deleteConsumable);
  IMPLEMENT_MOCK1(deleteLocation);
  IMPLEMENT_MOCK1(deleteBuilding);
  IMPLEMENT_MOCK1(deleteStructure);
};
