//
// Created by nolasco on 27/11/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "interface/model/ILookup.h"

class LookupMock : public trompeloeil::mock_interface<model::ILookup> {

  IMPLEMENT_MOCK1(itemsIn);
  IMPLEMENT_MOCK1(consumablesIn);
  IMPLEMENT_MOCK1(equippablesIn);
  IMPLEMENT_MOCK1(charactersIn);
  IMPLEMENT_MOCK1(structuresIn);
  IMPLEMENT_MOCK1(neighbourExteriors);
  IMPLEMENT_MOCK1(neighbourBuildings);
  IMPLEMENT_MOCK1(neighbourLocations);
  IMPLEMENT_MOCK1(neighboursEndingIn);
  IMPLEMENT_MOCK1(closeByLocations);
  IMPLEMENT_MOCK1(closeByCharacters);
  IMPLEMENT_MOCK1(closeByStructures);
  IMPLEMENT_MOCK1(closeByBuildings);
  IMPLEMENT_MOCK1(closeByExteriors);
  IMPLEMENT_MOCK1(whereIs);
  IMPLEMENT_MOCK0(playableCharacters);
  IMPLEMENT_MOCK2(consumableTypeIn);
  IMPLEMENT_MOCK1(type);
  IMPLEMENT_MOCK1(character);
  IMPLEMENT_MOCK1(item);
  IMPLEMENT_MOCK1(location);
  IMPLEMENT_MOCK1(characterExists);
};
