//
// Created by nolasco on 02/06/20.
//

#pragma once

#include "Verbose.h"

namespace view {

class Printer {
public:
  Printer(const Verbose verbose = Verbose::INFO);

  void setVerboseLevel(Verbose verbose);

private:
  Verbose verbose;
};

} // namespace view
