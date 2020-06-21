//
// Created by nolasco on 21/06/20.
//

#include "StreamConverter.h"

#include <sstream>

namespace view {

std::string toString(const entity::Character &character) {
  std::ostringstream os;
  os << "name: " << character.getName();
  return os.str();
}

} // namespace view