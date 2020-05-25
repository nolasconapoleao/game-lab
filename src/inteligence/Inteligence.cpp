//
// Created by nolasco on 25/05/20.
//

#include "Inteligence.h"

#include "common/Match.h"
#include "utils/MathUtils.h"

void Inteligence::smallBrain(Character &bot, World &world, std::vector<std::string> &convos) {
  const auto decision = MathUtils::random(1, 2);
  Inteligence::think(bot, world, convos, decision);
}

void Inteligence::think(Character &bot, World &world, std::vector<std::string> &convos, uint8_t decision) {
  switch (decision) {
    case 1: {
      Match::match(world.rooms[world.currentRoom], world.player, bot, convos);
      break;
    }
    default:
      convos.emplace_back(bot.talk());
  }
}
