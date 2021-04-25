//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "datatypes/controller/Decision.h"

// Forward declaration
class Snapshot;

namespace view::printer {

void printScreen(const Snapshot &snapshot, const Action &submenu, const bool clearFirst);
void history(const std::vector<Decision> &history);
void clearScreen();

} // namespace view::printer
