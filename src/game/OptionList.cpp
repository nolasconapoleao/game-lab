//
// Created by nolasco on 23/05/20.
//

#include "OptionList.h"

void OptionList::addOption(const std::string option) {
  options.emplace_back('0' + options.size() + 1, option);
}

void OptionList::clearOptions() {
  options.clear();
}

const uint8_t OptionList::numOptions() {
  return options.size() - 2;
}

void OptionList::addFooter() {
  options.emplace_back('b', "Back");
  options.emplace_back('e', "Exit");
}
