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
  const auto idTurn = loadNextCharacter();
  const auto snap = createSceneSnapshot(idTurn);
  auto decision
      = lookup->character(idTurn)->info.ghost == Ghost::PLAYER ? player.think(snap) : brain::computer::think(snap);
  handleCharacterTurn(decision);
}

bool GameEngine::isTerminated() {
  return characterQueue.empty();
}

CharacterId GameEngine::loadNextCharacter() {
  CharacterId idTurn;
  do {
    idTurn = *characterQueue.begin();
    characterQueue.erase(idTurn);
    if (characterQueue.empty()) {
      updateCharacterQueue();
    }
  } while (!lookup->characterExists(idTurn) && !characterQueue.empty());
  return idTurn;
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
    case Action::SKIP_TURN:
      break;
    case Action::ATTACK_BUILDING:
      handler->attackBuilding(decision.sender, decision.receiver);
      break;
    case Action::ATTACK_CHARACTER:
      handler->attackCharacter(decision.sender, decision.receiver);
      break;
    case Action::ATTACK_STRUCTURE:
      handler->attackStructure(decision.sender, decision.receiver);
      break;
    case Action::INVENTORY_USE:
      handler->useItem(decision.sender, decision.receiver);
      break;
    case Action::INVENTORY_PICKUP:
      handler->pickupItem(decision.sender, decision.receiver, decision.quantity);
      break;
    case Action::INVENTORY_DROP:
      handler->dropItem(decision.sender, decision.receiver, decision.quantity);
      break;
    case Action::TRAVEL_INTERIOR:
      [[fallthrough]];
    case Action::TRAVEL_EXTERIOR:
      handler->travel(decision.sender, decision.receiver);
      break;
    case Action::SHOP_BUY:
      handler->buyItem(decision.receiver, decision.sender, decision.quantity);
      break;
    case Action::SHOP_SELL:
      handler->sellItem(decision.receiver, decision.sender, decision.quantity);
      break;
    case Action::SPECIAL_PICKPOCKET:
      handler->stealItem(decision.sender, decision.receiver);
      break;
    case Action::SPECIAL_POSSESS:
      handler->possess(decision.sender, decision.receiver);
      break;
  }
}

} // namespace controller
