//
// Created by nolasco on characterId0/06/20.
//

#include "GameEngine.h"

#include <controller/brain-computer/ComputerBrain.h>
#include <controller/brain-player/PlayerBrain.h>
#include <model/handler/Handler.h>
#include <model/lookup/Lookup.h>

namespace controller {

GameEngine::GameEngine(const std::shared_ptr<model::Handler> &handler, const std::shared_ptr<model::Lookup> &lookup)
    : handler(std::move(handler)), lookup(std::move(lookup)) {
  handler->createWorld();
  updateCharacterQueue();
}

void GameEngine::run() {
  if (characterQueue.empty()) {
    updateCharacterQueue();
  }

  const auto idTurn = *characterQueue.begin();
  characterQueue.erase(idTurn);
  const auto snap = createSceneSnapshot(idTurn);
  auto decision = lookup->character(idTurn)->info.ghost == Ghost::PLAYER ? brain::player::think(snap)
                                                                         : brain::computer::think(snap);
  handleCharacterTurn(decision);
}

bool GameEngine::isTerminated() {
  return characterQueue.empty() && lookup->playableCharacters().empty();
}

void GameEngine::updateCharacterQueue() {
  for (const auto it : lookup->playableCharacters()) {
    characterQueue.insert(it.id);
    for (const auto k : lookup->closeByCharacters(it.id)) {
      characterQueue.insert(k.id);
    }
  }
}

Snapshot GameEngine::createSceneSnapshot(CharacterId characterId) {
  auto snap = Snapshot{
      {characterId, lookup->character(characterId)},
      lookup->whereIs(characterId),
      lookup->consumablesIn(characterId),
      lookup->equippablesIn(characterId),
      lookup->closeByCharacters(characterId),
      lookup->closeByStructures(characterId),
      lookup->closeByBuildings(characterId),
      lookup->closeByExteriors(characterId),
      lookup->itemsIn(lookup->whereIs(characterId).id),
  };
  snap.floor = lookup->itemsIn(snap.location.id);
  for (const auto it : snap.characters) {
    snap.ownedBy.emplace(it.id, lookup->itemsIn(it.id));
  }
  return snap;
}

void GameEngine::handleCharacterTurn(const Decision &decision) {
  switch (decision.type) {
    case ActionType::SKIP_TURN:
      break;
    case ActionType::ATTACK_BUILDING:
      handler->attackBuilding(decision.sender, decision.receiver);
      break;
    case ActionType::ATTACK_CHARACTER:
      handler->attackCharacter(decision.sender, decision.receiver);
      break;
    case ActionType::ATTACK_STRUCTURE:
      handler->attackStructure(decision.sender, decision.receiver);
      break;
    case ActionType::INVENTORY_USE:
      handler->useItem(decision.sender, decision.receiver);
      break;
    case ActionType::TRAVEL:
      handler->travel(decision.sender, decision.receiver);
      break;
  }
}

} // namespace controller
