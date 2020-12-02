//
// Created by nolasco on 05/06/20.
//

#include "RandomMock.h"

RandomMock mock;

namespace Random {

Quantity rand(Quantity lowerBound, Quantity upperBound) {
  return mock.rand(lowerBound, upperBound);
}

Quantity rand_range(Quantity number, Quantity range) {
  return mock.rand_range(number, range);
}

std::unordered_set<Quantity> multipleNonRepeated(Quantity quantity, Quantity lowerBound, Quantity upperBound) {
  return mock.multipleNonRepeated(quantity, lowerBound, upperBound);
}

} // namespace Random
