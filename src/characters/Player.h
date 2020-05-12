//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <ostream>

#include "BaseCharacter.h"

class Player : public BaseCharacter {
public:
  Player();
  std::string sayHi() override;
  void receiveAttack(uint attackPoints) override;
  std::string sayBye() override;
  friend std::ostream &operator<<(std::ostream &os, const Player &player);
};
