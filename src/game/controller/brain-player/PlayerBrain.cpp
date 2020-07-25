//
// Created by nolasco on 10/06/20.
//

#include "PlayerBrain.h"

namespace controller {

Decision brain::player::think(const Snapshot &snap) {
  return Decision{ActionType::SKIP_TURN};
}
} // namespace controller
