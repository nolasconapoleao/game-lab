//
// Created by nolasco on 27/11/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "interface/model/IFactory.h"

class FactoryMock : public trompeloeil::mock_interface<model::IFactory> {
  IMPLEMENT_MOCK4(createCharacter);
  IMPLEMENT_MOCK1(createEquipment);
  IMPLEMENT_MOCK1(createStaff);
  IMPLEMENT_MOCK1(createWeapon);
  IMPLEMENT_MOCK1(createEquippable);
  IMPLEMENT_MOCK2(createConsumable);
  IMPLEMENT_MOCK1(createConnector);
  IMPLEMENT_MOCK1(createBuilding);
  IMPLEMENT_MOCK1(createLocation);
  IMPLEMENT_MOCK1(createStructure);
};
