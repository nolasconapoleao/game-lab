//
// Created by nolasco on characterId0/06/20.
//

#include "GameEngine.h"

#include <model/handler/Handler.h>
#include <model/lookup/Lookup.h>

namespace controller {

GameEngine::GameEngine(const std::shared_ptr<model::Handler> handler, const std::shared_ptr<model::Lookup> lookup)
    : mHandler(std::move(handler)), mLookup(std::move(lookup)) {
  handler->createWorld();
  updateCharacterQueue();
}

void GameEngine::run() {
  const auto idTurn = loadNextCharacter();
  mSnapshot = createSceneSnapshot(idTurn);
  auto decision
      = mLookup->character(idTurn)->info.ghost == Ghost::PLAYER ? player.think(mSnapshot) : computer.think(mSnapshot);
  handleCharacterTurn(decision);
}

bool GameEngine::isTerminated() {
  return characterQueue.empty();
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
  if (!checker.isDecisionValid(mSnapshot, decision)) {
    // Skip turn
    return;
  }

  switch (decision.type) {
    case Action::ATTACK_BUILDING:
      mHandler->attackBuilding(decision.sender, decision.receiver);
      break;
    case Action::ATTACK_CHARACTER:
      mHandler->attackCharacter(decision.sender, decision.receiver);
      break;
    case Action::ATTACK_STRUCTURE:
      mHandler->attackStructure(decision.sender, decision.receiver);
      break;
    case Action::INVENTORY_USE:
      mHandler->useItem(decision.receiver);
      break;
    case Action::INVENTORY_PICKUP:
      mHandler->pickupItem(decision.sender, decision.receiver, decision.quantity);
      break;
    case Action::INVENTORY_DROP:
      mHandler->dropItem(decision.sender, decision.receiver, decision.quantity);
      break;
    case Action::TRAVEL_INTERIOR:
      [[fallthrough]];
    case Action::TRAVEL_EXTERIOR:
      mHandler->travel(decision.sender, decision.receiver);
      break;
    case Action::SHOP_BUY:
      mHandler->buyItem(decision.receiver, decision.sender, decision.quantity);
      break;
    case Action::SHOP_SELL:
      mHandler->sellItem(decision.receiver, decision.sender, decision.quantity);
      break;
    case Action::SPECIAL_PICKPOCKET:
      mHandler->stealItem(decision.sender, decision.receiver);
      break;
    case Action::SPECIAL_POSSESS:
      mHandler->possess(decision.sender, decision.receiver);
      break;
    case Action::SKIP_TURN:
      [[fallthrough]];
    default:
      break;
  }
}

} // namespace controller
