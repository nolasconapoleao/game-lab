//
// Created by nolasco on 13/05/20.
//

#include "InteractUtil.h"

void playerUsePotion(Player &player, const Potion &potion) {
  if ((player.currentHealthPoints + potion.modifierValue) < player.maxHealthPoints) {
    player.currentHealthPoints += potion.modifierValue;
  } else {
    player.currentHealthPoints = player.maxHealthPoints;
  }
}
