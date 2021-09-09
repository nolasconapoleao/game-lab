//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <memory>
#include <set>

#include "datatypes/GameTypes.h"
#include "datatypes/controller/Decision.h"
#include "datatypes/lookup/ResourceEntry.h"

// Forward declaration
namespace model {
class IHandler;
class ILookup;
} // namespace model

namespace controller {
class IDecisionChecker;
namespace brain {
class IBrain;
}

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

  std::shared_ptr<model::IHandler> mHandler;
  std::shared_ptr<model::ILookup> mLookup;
  std::set<CharacterId> characterQueue;
  std::shared_ptr<brain::IBrain> mPlayer;
  std::shared_ptr<brain::IBrain> mComputer;
  std::shared_ptr<IDecisionChecker> mDecisionChecker;
  Snapshot mSnapshot;
  std::vector<Decision> mHistory;
  bool mGameTerminated;
};

} // namespace controller
