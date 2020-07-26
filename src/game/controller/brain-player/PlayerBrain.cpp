//
// Created by nolasco on 10/06/20.
//

#include "PlayerBrain.h"

#include <controller/brain-player/input/Input.h>

#include "view/Printer.h"
#include "view/input-prompt/Input-Prompter.h"

namespace controller::brain::player {

Decision travel(const Snapshot &snap);

Decision think(const Snapshot &snap) {
  view::printer::printScreen(snap);
  return travel(snap);
  //  return Decision{ActionType::SKIP_TURN};
}

Decision travel(const Snapshot &snap) {
  view::input::travel(snap);
  const auto bLen = snap.buildings.size();
  const auto eLen = snap.exteriors.size();
  const auto in = controller::input::numeric(bLen + eLen) - 1;
  const auto destination = (in > bLen - 1) ? snap.buildings[in].id : snap.exteriors[in - bLen].id;
  return Decision{ActionType::TRAVEL, snap.character.id, destination};
}

} // namespace controller::brain::player
