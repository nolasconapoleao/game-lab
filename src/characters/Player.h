//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <ostream>

#include "BaseCharacter.h"

/**
 * @brief Player class, 20 health and 3 attack points.
 */
class Player : public BaseCharacter {
public:
  Player();
  std::string sayHi() override;
  std::string sayBye() override;
};
