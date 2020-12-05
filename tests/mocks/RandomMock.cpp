//
// Created by nolasco on 05/06/20.
//

#include "RandomMock.h"

RandomMock mock;

namespace Random {

Quantity rand(const Quantity lowerBound, const Quantity upperBound) {
  return mock.rand(lowerBound, upperBound);
}

Quantity rand_range(const Quantity number, const Quantity range) {
  return mock.rand_range(number, range);
}

std::unordered_set<Quantity> multipleNonRepeated(const Quantity quantity, const Quantity lowerBound,
                                                 const Quantity upperBound) {
  return mock.multipleNonRepeated(quantity, lowerBound, upperBound);
}

} // namespace Random
