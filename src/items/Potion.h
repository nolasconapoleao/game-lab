//
// Created by nolasco on 11/05/20.
//

#pragma once

#include "BaseItem.h"

/**
 * @brief A basic potion, recovers 3 points health.
 */
class Potion : public BaseItem {
public:
  Potion();

  std::string description;
};
