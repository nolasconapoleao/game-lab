//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <ostream>

#include "BaseCharacter.h"

class Enemy : public BaseCharacter {
public:
  Enemy();
  std::string sayHi() override;
  std::string sayBye() override;

  friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy);
};
