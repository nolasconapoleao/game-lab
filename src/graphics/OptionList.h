//
// Created by nolasco on 23/05/20.
//

#pragma once

#include <ostream>
#include <vector>

class OptionList {
public:
  void addOption(const std::string option);
  void clearOptions();
  const uint8_t numOptions();
  void addFooter();
  friend std::ostream &operator<<(std::ostream &os, const OptionList &list);

  std::vector<std::pair<uint8_t, std::string>> options;
};
