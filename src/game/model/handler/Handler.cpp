//
// Created by nolasco on 20/06/20.
//

#include "Handler.h"

#include "game/view/entity/StreamConverter.h"

// TODO: mvc model does not need to access this
void Handler::strategize(CharacterId characterId) {
  // TODO: use character inteligence, occupation, health, location
  const auto character = World::character(characterId);

  if (character.getStats().hp > 2) {
    battle(characterId, characterId, World::activeLocation);
  }
}
