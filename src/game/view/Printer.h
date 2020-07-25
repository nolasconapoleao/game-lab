//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "datatypes/state/LogicState.h"

// Forward declaration
class Snapshot;

namespace view::printer {

void printScreen(const Snapshot &snapshot);

} // namespace view::printer
