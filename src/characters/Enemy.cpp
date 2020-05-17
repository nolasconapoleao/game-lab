//
// Created by nolasco on 10/05/20.
//

#include "Enemy.h"

Enemy::Enemy() : BaseCharacter("Enemy", 10, 2){};

std::string Enemy::sayHi() {
  return "Prepare to fight!";
}

std::string Enemy::sayBye() {
  return "Dude chillout, we should be friends!";
}
