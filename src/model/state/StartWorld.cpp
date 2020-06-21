//
// Created by nolasco on 11/06/20.
//

#include "StartWorld.h"

enum STATES : StateId {
  CREATE_WORLD = 1,
  POPULATE_LOCATIONS,
  CREATE_PLAYER,
};

namespace model::state {

StartWorld::StartWorld() {
  addState(CREATE_WORLD, "Load next character from list");
  addState(POPULATE_LOCATIONS, "Handle character action");
  addState(CREATE_PLAYER, "Get next character");

  addTransition(STATE_STANDBYE, CREATE_WORLD, 's');
  addTransition(CREATE_WORLD, POPULATE_LOCATIONS, '1');
  addTransition(POPULATE_LOCATIONS, CREATE_PLAYER, '2');
  addTransition(CREATE_PLAYER, STATE_STANDBYE, 'b');
}

void StartWorld::whatsUp() {
  // FIXME: [nn] This state is not fully fleshed out
  switch (activeState) {

    case CREATE_WORLD: {
      factory.createLocation(LocationPrototype::TOWN);
    }

    case POPULATE_LOCATIONS: {
      factory.createCharacter(Occupation::BEGGAR);
      factory.createItem(ItemPrototype::SHIELD);
    }

    case CREATE_PLAYER: {
      factory.createCharacter(Occupation::PLAYER);
    }
  }
  continueToNext();
}

void StartWorld::continueToNext() {
  auto neighbours = stateNetwork.neighbours(activeState);
  auto transition = stateNetwork.getEdge(LinkId{activeState, neighbours[0]});
  triggerTransition(transition);
}

} // namespace model::state