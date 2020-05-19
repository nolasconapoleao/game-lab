//
// Created by nolasco on 19/05/20.
//

#pragma once

#include "BaseCharacter.h"

/**
 * @brief Player class, 20 health and 3 attack points.
 */
class Shopkeeper : public BaseCharacter {
public:
  Shopkeeper();

  std::string sayHi() override;
  std::string sayBye() override;
};
