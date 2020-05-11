//
// Created by nolasco on 10/05/20.
//

#include "Enemy.h"

Enemy::Enemy() : BaseCharacter(10, 2){};

std::string Enemy::sayHi() { return "Prepare to fight!"; }

void Enemy::receiveAttack(uint attackPoints) {
  if (currentHealthPoints >= attackPoints) {
    currentHealthPoints -= attackPoints;
  } else {
    currentHealthPoints = 0;
  }
}

std::string Enemy::sayBye() { return "Dude chillout, we should be friends!"; }
