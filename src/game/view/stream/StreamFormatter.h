//
// Created by nolasco on 21/06/20.
//

#pragma once

#include <string>

namespace view::stream {

const std::string effectHeader();
[[maybe_unused]] const std::string statsHeader();
[[maybe_unused]] const std::string itemHeader();
const std::string infoHeader();
const std::string statDesc(const std::string &value);

} // namespace view::stream
