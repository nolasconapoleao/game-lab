//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <memory>
#include <set>

#include "DecisionChecker.h"
#include "controller/brain/ComputerBrain.h"
#include "controller/brain/PlayerBrain.h"
#include "datatypes/GameTypes.h"
#include "datatypes/controller/Decision.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace model {

// Forward declaration
class IHandler;
class ILookup;
} // namespace model

namespace controller {

/// @brief Game turn mHandler.
class GameEngine {
public:
  /**
   * @brief Constructor.
   * @param handler game entity controller.
   * @param lookup game entity finder.
   */
  GameEngine(std::shared_ptr<model::IHandler> handler, std::shared_ptr<model::ILookup> lookup);

  /// @brief Executes instructions for activeSubmenu character.
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

  std::shared_ptr<model::IHandler> mHandler;
  std::shared_ptr<model::ILookup> mLookup;
  std::vector<Decision> history;
  brain::Player player;
  brain::Computer computer;
  DecisionChecker checker;
  Snapshot mSnapshot;
  bool mGameTerminated;
};

} // namespace controller
