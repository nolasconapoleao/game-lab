//
// Created by nolasco on 08/07/20.
//

#include "Handler.h"
#include "math/gamemath.h"

constexpr Number MAXCASH = 100'000;

void Handler::transferMoney(const CharacterId originId, const CharacterId destinationId, const Quantity amount) {
  auto &origin = World::character(originId);
  auto &destination = World::character(destinationId);

  auto updatedOriginStats = origin.getStats();
  updatedOriginStats.cash = gamemath::clamp_sub(updatedOriginStats.cash, amount, 0);
  auto updatedDestinationStats = destination.getStats();
  updatedDestinationStats.cash = gamemath::clamp_add(updatedDestinationStats.cash, amount, MAXCASH);

  origin.setBaseStats(updatedOriginStats);
  destination.setBaseStats(updatedDestinationStats);
}
