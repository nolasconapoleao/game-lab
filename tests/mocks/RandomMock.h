//
// Created by nolasco on 05/06/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "random/Random.h"

class RandomMock {
public:
  MAKE_MOCK2(rand, Quantity(const Quantity, const Quantity));
  MAKE_MOCK2(rand_range, Quantity(const Quantity, const Quantity));
  MAKE_MOCK3(multipleNonRepeated, std::unordered_set<Quantity>(const Quantity, const Quantity, const Quantity));
};

extern RandomMock mock;
