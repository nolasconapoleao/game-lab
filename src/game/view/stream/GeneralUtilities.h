//
// Created by nolasco on 23/11/20.
//

#pragma once

#include <memory>
#include <unordered_set>
#include <vector>

#include "datatypes/lookup/ResourceEntry.h"

namespace view::stream {

template <class T> std::ostream &operator<<(std::ostream &os, const std::shared_ptr<T> &value) {
  os << *value.get();
  return os;
}

template <class T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector) {
  for (const auto &it : vector) {
    os << "\n"
       << "\t" << it;
  }
  return os;
}

template <class T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &unorderedSet) {
  for (const auto &it : unorderedSet) {
    os << "\n" << it << "\t";
  }
  return os;
}

template <class T> std::ostream &operator<<(std::ostream &os, const DbEntry<T> &entry) {
  os << entry.entity->name;
  return os;
}

} // namespace view::stream
