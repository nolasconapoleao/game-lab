//
// Created by nolasco on 10/05/20.
//

#include "Player.h"

Player::Player() : BaseCharacter(20, 3){};

std::string Player::sayHi() { return "Help me get to the end of the maze!"; }

void Player::receiveAttack(uint attackPoints) {
  if (currentHealthPoints >= attackPoints) {
    currentHealthPoints -= attackPoints;
  } else {
    currentHealthPoints = 0;
  }
}

std::string Player::sayBye() { return "You've failed me!"; }
