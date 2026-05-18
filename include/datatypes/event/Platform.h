//
// Created by nolasco on 09/07/20.
//

#pragma once

#include <string>
#include <vector>

using Score = int8_t;

/// @brief Event with multiple options.
struct Platform {
  /// @brief Header for console print.
  std::string OptionHeader;
  /// @brief List of alternatives and scores.
  std::vector<std::pair<std::string, Score>> alternatives;
};
