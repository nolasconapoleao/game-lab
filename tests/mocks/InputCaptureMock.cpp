//
// Created by nolasco on 02/06/20.
//

#include "InputCaptureMock.h"

#include <iostream>

InputCaptureMock mock;

namespace controller::input {

std::string sentence(bool flushFirst) {
  return mock.sentence(flushFirst);
}

char alphanum(const std::string &options) {
  return mock.alphanum(options);
}

Quantity numeric(const Quantity upperBound) {
  return mock.numeric(upperBound);
}

} // namespace controller::input
