//
// Created by nolasco on 10/06/20.
//

#include "EventManager.h"

#include <game/controller/state/include/Substate.h>
#include <game/controller/state/include/Transition.h>

#include "game/controller/event/Example.h"
#include "game/controller/event/GuessWhat.h"
#include "game/controller/input/Input.h"
#include "game/controller/state/Start.h"
#include "game/view/entity/StreamConverter.h"

namespace controller {

void EventManager::run() {
  CharacterId id = World::activeCharacter;
  if (gameEvents.contains(World::activeCharacter)) {
    if (gameEvents.find(id)->second->activeState() == Cancel
        || gameEvents.find(id)->second->activeState() == TERMINATED) {
      gameEvents.erase(gameEvents.find(id));
    } else {
      gameEvents.find(id)->second->triggerTransition(START);
      gameEvents.find(id)->second->run();
    }
  }
}

bool EventManager::isTerminated() {
  return !gameEvents.contains(World::activeCharacter);
}

void EventManager::addEvent(bool isMaze, CrabDifficulty difficulty, ResourceId origin, ResourceId destination,
                            int8_t exitScore) {
  gameEvents.insert({destination, std::make_shared<Example>(false, CRABMODE, origin, -5)});
  gameEvents.insert({destination, std::make_shared<GuessWhat>(false, CRABMODE, origin, -5)});
}

} // namespace controller
