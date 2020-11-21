//
// Created by nolasco on 02/06/20.
//

#include "Input-Prompter.h"

#include <view/stream/StreamConverter.h>

using namespace view::stream;

namespace view::input {

void playerMenu(const std::vector<PlayerState> &options) {
  for (const auto &it : options) {
    std::cout << "\t" << it.transition << ": " << it.prompt << "\n";
  }
}

void invalid(const std::string_view &header) {
  std::cout << "Cannot " << header << "\n";
}

void quantity(Quantity max) {
  std::cout << "How much do you want? Maximum is " << max << "\n";
}

void items(const std::string_view &header, const Snapshot &snapshot) {
  std::cout << separatorClose << " " << header << "\n";
  std::cout << separatorClose << "Select item:\n";
  auto k = 1;
  for (const auto &it : snapshot.equippables) {
    std::cout << "\t" << k << ": " << it.entity->name << "\n";
    k++;
  }
  for (const auto &it : snapshot.consumables) {
    std::cout << "\t" << k << ": " << it.entity->name << "\n";
    k++;
  }
}

} // namespace view::input
