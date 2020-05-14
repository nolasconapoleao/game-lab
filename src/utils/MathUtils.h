//
// Created by nolasco on 14/05/20.
//

#pragma once

#include <zconf.h>

namespace MathUtils {

uint clamp_sub(uint minuend, uint subtrahend, uint lowerBound);
uint clamp_add(uint augend, uint addend, uint upperBound);
uint clamp(uint num, uint lowerBound, uint upperBound);

}; // namespace MathUtils
