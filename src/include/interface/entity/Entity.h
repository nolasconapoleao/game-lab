//
// Created by nolasco on 19/07/20.
//

#pragma once

#include <string>

namespace entity {

class Entity {
public:
  Entity(const std::string &name) : name(name) {
  }

  std::string name;
};

} // namespace entity
