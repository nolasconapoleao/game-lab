//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "datatypes/controller/MenuState.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace input::prompt {

[[maybe_unused]] constexpr auto separatorOpen = "<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
constexpr auto separatorClose = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>";

// TODO: playerMenu and generic have the same structure
void playerMenu(const std::vector<MenuState> &options);
void quantity(Quantity max);
void items(const std::string_view &header, const Snapshot &snapshot);

template <typename T> void generic(const std::string_view &header, const std::vector<T> &entities) {
  std::cout << separatorClose << " " << header << ":\n";
  auto k = 1;
  for (const auto &it : entities) {
    std::cout << "\t" << k << ": " << it.entity->name << "\n";
    k++;
  }
}

} // namespace input::prompt
