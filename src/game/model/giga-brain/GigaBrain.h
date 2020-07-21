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
  void beggarThink(const CharacterId characterId);
  void blacksmithThink(const CharacterId characterId);
  void jesterThink(const CharacterId characterId);
  void librarianThink(const CharacterId characterId);
  void mercenaryThink(const CharacterId characterId);
  void shopkeeperThink(const CharacterId characterId);
  void thiefThink(const CharacterId characterId);
  void touristThink(const CharacterId characterId);
  std::shared_ptr<Handler> handler;
  std::shared_ptr<Lookup> lookup;
};

} // namespace model
