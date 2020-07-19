//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <map>
#include <memory>
#include <set>

#include "interface/event/KingCrab.h"
#include "interface/state-machine/StateMachine.h"
#include "model/World.h"
#include "model/handler/Handler.h"
#include "view/Printer.h"

namespace controller {

// TODO: EventManager should inherit from StateMachine
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
