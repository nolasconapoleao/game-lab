//
// Created by nolasco on 05/06/20.
//

#pragma once

#include <trompeloeil/include/trompeloeil.hpp>

#include "input/capture/InputCapture.h"

class InputCaptureMock {
public:
  MAKE_MOCK1(sentence, std::string(bool));
  MAKE_MOCK1(alphanum, char(const std::string &));
  MAKE_MOCK1(numeric, Quantity(Quantity));
};

extern InputCaptureMock mock;
