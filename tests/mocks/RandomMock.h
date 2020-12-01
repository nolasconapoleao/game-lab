//
// Created by nolasco on 05/06/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "libs/random/Random.h"

class RandomMock {
public:
  MAKE_MOCK2(rand, Quantity(Quantity, Quantity));
  MAKE_MOCK2(rand_range, Quantity(Quantity, Quantity));
  MAKE_MOCK3(multipleNonRepeated, std::unordered_set<Quantity>(Quantity, Quantity, Number));
};

extern RandomMock mock;
