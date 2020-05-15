//
// Created by nolasco on 13/05/20.
//

#include "InteractUtils.h"

#include "utils/MathUtils.h"

void playerUsePotion(Player &player, const Potion &potion) {
  player.currentHealthPoints =
      MathUtils::clamp_add(player.currentHealthPoints, potion.modifierValue, player.maxHealthPoints);
}
