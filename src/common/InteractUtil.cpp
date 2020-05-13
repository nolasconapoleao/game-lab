//
// Created by nolasco on 13/05/20.
//

#include "InteractUtil.h"

void playerUsePotion(Player &player, const Potion &potion) {
  if ((player.currentHealthPoints + potion.value) < player.maxHealthPoints) {
    player.currentHealthPoints += potion.value;
  } else {
    player.currentHealthPoints = player.maxHealthPoints;
  }
}
