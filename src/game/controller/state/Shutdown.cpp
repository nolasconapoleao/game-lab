//
// Created by nolasco on 21/06/20.
//

#include "Shutdown.h"

namespace controller {

Shutdown::Shutdown() {
  createNetwork();
}

void Shutdown::fillStateOption() {
  // Intentionally left blank
}

void Shutdown::execute() {
  view::Printer::directPrint("Game over.");
}

} // namespace controller