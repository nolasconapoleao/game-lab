//
// Created by nolasco on 10/05/20.
//

#include "Player.h"

Player::Player() : BaseCharacter(20, 3){};

std::string Player::sayHi() {
  return "Help me, get to the end of the maze!";
}

std::string Player::sayBye() {
  return "You've failed me!";
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
  os << "Player HP: " << player.currentHealthPoints << "/" << player.maxHealthPoints << std::endl;
  return os;
}
