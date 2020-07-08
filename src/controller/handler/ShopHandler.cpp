//
// Created by nolasco on 08/07/20.
//

#include "Controller.h"
#include "controller/handler/include/gamemath.h"

constexpr Number MAXCASH = 100'000;

void Controller::transferMoney(const CharacterId originId, const CharacterId destinationId, const Quantity amount) {
  auto &origin = world.character(originId);
  auto &destination = world.character(destinationId);

  auto updatedOriginStats = origin.getStats();
  updatedOriginStats.cash = gamemath::clamp_sub(updatedOriginStats.cash, amount, 0);
  auto updatedDestinationStats = destination.getStats();
  updatedDestinationStats.cash = gamemath::clamp_add(updatedDestinationStats.cash, amount, MAXCASH);

  origin.setBaseStats(updatedOriginStats);
  destination.setBaseStats(updatedDestinationStats);
}
