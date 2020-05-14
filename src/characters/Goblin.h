//
// Created by nolasco on 14/05/20.
//

#include <string>

#include "BaseCharacter.h"

#pragma once

class Goblin : public BaseCharacter {
public:
  Goblin();
  std::string sayHi() override;
  std::string sayBye() override;

  friend std::ostream &operator<<(std::ostream &os, const Goblin &goblin);
};
