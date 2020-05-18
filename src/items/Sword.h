//
// Created by nolasco on 16/05/20.
//

#pragma once

#include "BaseItem.h"

/**
 * @brief A basic swrod, increases 2 attack points.
 */
class Sword : public BaseItem {
public:
  Sword();

  std::string description;
};
