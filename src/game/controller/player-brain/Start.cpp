//
// Created by nolasco on 11/06/20.
//

#include "Start.h"

namespace controller {

Start::Start() {
  createNetwork();
}

void Start::fillStateOption() {
  // Intentionally left blank
}

void Start::execute() {
  mFactory.createWorld();
}

} // namespace controller