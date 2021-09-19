//
// Created by nolasco on 10/06/20.
//

#include "GameEngine.h"

#include "controller/DecisionChecker.h"
#include "controller/brain/ComputerBrain.h"
#include "controller/brain/PlayerBrain.h"
#include "model/handler/Handler.h"
#include "model/lookup/Lookup.h"
#include "view/Printer.h"

namespace controller {

GameEngine::GameEngine(const std::shared_ptr<model::IHandler> handler, const std::shared_ptr<model::ILookup> lookup)
    : mHandler(std::move(handler))
    , mLookup(std::move(lookup))
    , mPlayer(std::make_shared<brain::Player>())
    , mComputer(std::make_shared<brain::Computer>())
    , mDecisionChecker(std::make_shared<DecisionChecker>())
    , mGameTerminated(false) {
  handler->createWorld();
  updateCharacterQueue();
}

void GameEngine::run() {
  const auto idTurn = loadNextCharacter();
  mSnapshot = createSceneSnapshot(idTurn);
  Decision decision{};
  if (mLookup->character(idTurn)->info.ghost == Ghost::PLAYER) {
    view::printer::history(mHistory);
    mHistory.clear();
    decision = mPlayer->think(mSnapshot);
    view::printer::clearScreen();
  } else {
    decision = mComputer->think(mSnapshot);
  }
  handleCharacterTurn(decision);
}

bool GameEngine::isTerminated() {
  return characterQueue.empty() || mGameTerminated;
}

CharacterId GameEngine::loadNextCharacter() {
  CharacterId idTurn{0};
  do {
    idTurn = *characterQueue.begin();
    characterQueue.erase(idTurn);
    if (characterQueue.empty()) {
      updateCharacterQueue();
    }
  } while (!mLookup->characterExists(idTurn) && !characterQueue.empty());
  return idTurn;
}

void GameEngine::updateCharacterQueue() {
  for (const auto &character : mLookup->playableCharacters()) {
    characterQueue.insert(character.id);
    for (const auto &characterNeighbour : mLookup->closeByCharacters(character.id)) {
      characterQueue.insert(characterNeighbour.id);
    }
  }
}

Snapshot GameEngine::createSceneSnapshot(CharacterId characterId) {
  auto snap = Snapshot{{characterId, mLookup->character(characterId)},
                       mLookup->whereIs(characterId),
                       mLookup->consumablesIn(characterId),
                       mLookup->equippablesIn(characterId),
                       mLookup->closeByCharacters(characterId),
                       mLookup->closeByStructures(characterId),
                       mLookup->closeByBuildings(characterId),
                       mLookup->closeByExteriors(characterId),
                       mLookup->itemsIn(mLookup->whereIs(characterId).id),
                       {}};
  for (const auto &character : snap.characters) {
    snap.ownedBy.emplace(character.id, mLookup->itemsIn(character.id));
  }
  return snap;
}

void GameEngine::handleCharacterTurn(const Decision &decision) {
  if (!mDecisionChecker->isDecisionValid(mSnapshot, decision)) {
    // Skip turn
    mHistory.emplace_back(Decision{Action::SKIP_TURN, mSnapshot.character.id});
    return;
  }

  mHistory.emplace_back(decision);
  switch (decision.action) {
    case Action::ATTACK_BUILDING:
      mHandler->attackBuilding(decision.subject, decision.object);
      break;
    case Action::ATTACK_CHARACTER:
      mHandler->attackCharacter(decision.subject, decision.object);
      break;
    case Action::ATTACK_STRUCTURE:
      mHandler->attackStructure(decision.subject, decision.object);
      break;
    case Action::INVENTORY_USE:
      mHandler->useItem(decision.object);
      break;
    case Action::INVENTORY_PICKUP:
      mHandler->pickupItem(decision.subject, decision.object, decision.quantity);
      break;
    case Action::INVENTORY_DROP:
      mHandler->dropItem(decision.subject, decision.object, decision.quantity);
      break;
    case Action::TRAVEL_INTERIOR:
      [[fallthrough]];
    case Action::TRAVEL_EXTERIOR:
      mHandler->travel(decision.subject, decision.object);
      break;
    case Action::SHOP_BUY:
      mHandler->buyItem(decision.object, decision.subject, decision.quantity);
      break;
    case Action::SHOP_SELL:
      mHandler->sellItem(decision.object, decision.subject, decision.quantity);
      break;
    case Action::SPECIAL_PICKPOCKET:
      mHandler->stealItem(decision.subject, decision.object);
      break;
    case Action::SPECIAL_POSSESS:
      mHandler->possess(decision.subject, decision.object);
      break;
    case Action::MENU_TERMINATE:
      mGameTerminated = true;
      break;
    case Action::SKIP_TURN:
      [[fallthrough]];
    default:
      break;
  }
}

} // namespace controller
