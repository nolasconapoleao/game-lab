//
// Created by nolasco on 21/06/20.
//

#pragma once

#include <string>

namespace view::stream {

std::string effectHeader();
[[maybe_unused]] std::string statsHeader();
[[maybe_unused]] std::string itemHeader();
std::string infoHeader();
std::string statDesc(const std::string &value);

} // namespace view::stream
