//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <controller/brain-player/PlayerBrain.h>
#include <datatypes/GameTypes.h>
#include <datatypes/controller/Decision.h>
#include <datatypes/lookup/ResourceEntry.h>
#include <memory>
#include <set>

namespace model {

// Forward declaration
class Handler;
class Lookup;
} // namespace model

namespace controller {

class GameEngine {
public:
  GameEngine(const std::shared_ptr<model::Handler> &handler, const std::shared_ptr<model::Lookup> &lookup);
  void run();
  bool isTerminated();

private:
  CharacterId loadNextCharacter();
  void updateCharacterQueue();
  Snapshot createSceneSnapshot(const CharacterId characterId);
  void handleCharacterTurn(const Decision &decision);
  std::set<CharacterId> characterQueue;

  std::shared_ptr<model::Handler> handler;
  std::shared_ptr<model::Lookup> lookup;
  std::vector<std::string> history;
  brain::player player;
};

} // namespace controller
