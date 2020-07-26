//
// Created by nolasco on 21/07/20.
//

#include "ComputerBrain.h"

#include <datatypes/entity-aux/Occupation.h>

#include "libs/random/Random.h"

using namespace Random;

namespace controller::brain::computer {
// TODO: remove this from here
Decision attack(const Snapshot &snap);
Decision inventory(const Snapshot &snap);
Decision tourist(const Snapshot &snap);

Decision think(const Snapshot &snap) {
  if (rand(0, 5) == 0) {
    return attack(snap);
  } else if (rand(0, 5) == 0) {
    return tourist(snap);
  } else if (rand(0, 2) == 0) {
    return inventory(snap);
  }

  const auto &character = snap.character.entity;
  switch (character->info.occupation) {
    case Occupation::BEGGAR:
      break;
    case Occupation::BLACKSMITH:
      break;
    case Occupation::JESTER:
      break;
    case Occupation::LIBRARIAN:
      break;
    case Occupation::MERCENARY:
      return attack(snap);
    case Occupation::SHOPKEEPER:
      break;
    case Occupation::THIEF:
      break;
    case Occupation::TOURIST:
      break;
  }
  return Decision{Action::SKIP_TURN};
}

Decision attack(const Snapshot &snap) {
  if (!snap.characters.empty() && rand(0, 5) == 0) {
    const auto attackedId = fromVec(snap.characters).id;
    return Decision{Action::ATTACK_CHARACTER, snap.character.id, attackedId};
  } else if (!snap.structures.empty() && rand(0, 7) == 0) {
    const auto attackedId = fromVec(snap.structures).id;
    return Decision{Action::ATTACK_STRUCTURE, snap.character.id, attackedId};
  } else if (!snap.buildings.empty() && rand(0, 15) == 0) {
    const auto attackedId = fromVec(snap.buildings).id;
    return Decision{Action::ATTACK_BUILDING, snap.character.id, attackedId};
  } else {
    return Decision{Action::SKIP_TURN};
  }
}

Decision inventory(const Snapshot &snap) {
  if (!snap.consumables.empty() && rand(0, 2) == 0) {
    const auto item = fromVec(snap.consumables);
    return Decision{Action::INVENTORY_USE, snap.character.id, item.id};
  } else if (!snap.equippables.empty() && rand(0, 5) == 0) {
    const auto item = fromVec(snap.equippables);
    if (item.entity->equipped) {
      return Decision{Action::INVENTORY_USE, snap.character.id, item.id};
    } else {
      return Decision{Action::SKIP_TURN};
    }
  } else {
    return Decision{Action::SKIP_TURN};
  }
}

Decision tourist(const Snapshot &snap) {
  if (!snap.exteriors.empty() && rand(0, 15) == 0) {
    const auto locationId = fromVec(snap.exteriors).id;
    return Decision{Action::TRAVEL, snap.character.id, locationId};
  } else {
    return Decision{Action::SKIP_TURN};
  }
}

} // namespace controller::brain::computer
