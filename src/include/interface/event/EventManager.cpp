//
// Created by nolasco on 10/06/20.
//

#include "EventManager.h"

#include "controller/event/Example.h"
#include "controller/event/GuessWhat.h"
#include "controller/input/Input.h"
#include "controller/state/Start.h"
#include "datatypes/state/Substate.h"
#include "datatypes/state/Transition.h"
#include "view/entity/Converter.h"

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
