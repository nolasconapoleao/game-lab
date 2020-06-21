//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <common/GameTypes.h>
#include <string>

namespace entity {

class Structure {
public:
  Structure(const std::string &name, const Size &size);

private:
  std::string name;
  Size size;
};

} // namespace entity
