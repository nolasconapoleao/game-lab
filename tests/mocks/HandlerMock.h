//
// Created by nolasco on 27/11/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "interface/model/IHandler.h"

class HandlerMock : public trompeloeil::mock_interface<model::IHandler> {
  IMPLEMENT_MOCK0(createWorld);
  IMPLEMENT_MOCK0(destroyWorld);
  IMPLEMENT_MOCK2(attackCharacter);
  IMPLEMENT_MOCK2(attackStructure);
  IMPLEMENT_MOCK2(attackBuilding);
  IMPLEMENT_MOCK3(dropItem);
  IMPLEMENT_MOCK3(pickupItem);
  IMPLEMENT_MOCK2(stealItem);
  IMPLEMENT_MOCK1(useItem);
  IMPLEMENT_MOCK1(depleteItem);
  IMPLEMENT_MOCK1(characterItemDepletion);
  IMPLEMENT_MOCK3(buyItem);
  IMPLEMENT_MOCK3(sellItem);
  IMPLEMENT_MOCK2(travel);
  IMPLEMENT_MOCK2(possess);
  IMPLEMENT_MOCK2(renameCharacter);
  IMPLEMENT_MOCK2(renameTeam);
};
