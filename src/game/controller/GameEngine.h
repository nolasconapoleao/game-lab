//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <controller/brain/ComputerBrain.h>
#include <controller/brain/PlayerBrain.h>
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

/// @brief Game turn handler.
class GameEngine {
public:
  /**
   * @brief Constructor.
   * @param handler game entity controller.
   * @param lookup game entity finder.
   */
  GameEngine(const std::shared_ptr<model::Handler> handler, const std::shared_ptr<model::Lookup> lookup);

  /// @brief Executes instructions for active character.
  void run();

  /**
   * @brief Game engine was terminated.
   * @return true if game was terminated.
   */
  bool isTerminated();

private:
  CharacterId loadNextCharacter();
  void updateCharacterQueue();
  Snapshot createSceneSnapshot(CharacterId characterId);
  void handleCharacterTurn(const Decision &decision);
  std::set<CharacterId> characterQueue;

  std::shared_ptr<model::Handler> handler;
  std::shared_ptr<model::Lookup> lookup;
  std::vector<std::string> history;
  brain::Player player;
  brain::Computer computer;
};

} // namespace controller
