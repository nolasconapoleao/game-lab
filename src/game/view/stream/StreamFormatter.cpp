//
// Created by nolasco on 21/06/20.
//

#include "StreamFormatter.h"

#include <iomanip>

#include "StreamConverter.h"

namespace view::stream {

const std::string effectHeader() {
  std::ostringstream os;
  os << statDesc("hp") << statDesc("atk") << statDesc("def") << statDesc("mAtk") << statDesc("mDef") << statDesc("spd")
     << statDesc("inte") << statDesc("acc") << statDesc("ste") << statDesc("mana") << statDesc("ran");
  return os.str();
}

const std::string statsHeader() {
  std::ostringstream os;
  os << std::string(NAME_LEN + 2, ' ') << statDesc("mhp") << statDesc("cst") << statDesc("lvl") << statDesc("xp")
     << effectHeader();
  return os.str();
}

const std::string itemHeader() {
  std::ostringstream os;
  os << std::string(NAME_LEN + 22, ' ') << effectHeader() << statDesc("quan") << statDesc("weig") << statDesc("pric");
  return os.str();
}

const std::string infoHeader() {
  return "HP Cash             Race  Class  Occupation";
}

const std::string statDesc(const std::string &value) {
  std::ostringstream os;
  os << std::setw(STAT_LEN) << value;
  return os.str();
}

} // namespace view::stream
