//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Entity.h"

namespace entity {

class Team : public Entity {
public:
  explicit Team(const std::string &name);
};

} // namespace entity