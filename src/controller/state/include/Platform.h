//
// Created by nolasco on 09/07/20.
//

#pragma once

#include <string>
#include <vector>

using Score = int8_t;

struct Platform {
  std::string OptionHeader;
  std::vector<std::pair<std::string, Score>> alternatives;
};
