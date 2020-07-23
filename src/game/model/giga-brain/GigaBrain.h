//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "model/handler/Handler.h"
#include "model/lookup/Lookup.h"

namespace model {

// Forward declaration
class Handler;
class Lookup;

class GigaBrain {
public:
  GigaBrain(const std::shared_ptr<Handler> &handler, const std::shared_ptr<Lookup> &lookup);
  void characterThink(const CharacterId characterId);

private:
  bool attackThought(const CharacterId characterId);
  bool inventoryThought(const CharacterId characterId);
  bool thiefThought(const CharacterId characterId);
  bool touristThought(const CharacterId characterId);
  std::shared_ptr<Handler> handler;
  std::shared_ptr<Lookup> lookup;
};

} // namespace model
