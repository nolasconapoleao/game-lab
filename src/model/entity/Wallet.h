//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <cstdint>

namespace entity {

struct Wallet {
  Quantity weight = 0;         // weight
  Quantity lvl = 0;            // level
  Quantity xp = 0;             // experience
  Quantity cash = 0;           // money
  std::string faction = "";    // faction
  std::string party = "";      // party
  std::string occupation = ""; // occupation
  std::string charClass = "";  // class
};

} // namespace entity