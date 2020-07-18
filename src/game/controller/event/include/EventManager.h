//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <set>

#include "game/controller/event/include/KingCrab.h"
#include "game/model/World.h"
#include "game/model/handler/Handler.h"
#include "game/view/Printer.h"
#include "state-machine/StateMachine.h"

namespace controller {

class EventManager {
public:
  void run();
  bool isTerminated();
  void addEvent(bool isMaze, CrabDifficulty difficulty, ResourceId origin, ResourceId destination, int8_t exitScore);

private:
  Handler controller;
  std::multimap<ResourceId, std::shared_ptr<KingCrab>> gameEvents;
};

} // namespace controller
