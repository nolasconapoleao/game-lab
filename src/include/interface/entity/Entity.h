//
// Created by nolasco on 19/07/20.
//

#pragma once

#include <string>
#include <utility>

namespace entity {

class Entity {
public:
  explicit Entity(std::string name) : name(std::move(name)) {
  }

  std::string name;
};

} // namespace entity
