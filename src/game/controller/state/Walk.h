//
// Created by nolasco on 24/06/20.
//

#pragma once

#include "interface/state/Caterpillar.h"

namespace controller {

class Walk : public Caterpillar {
public:
  Walk();

private:
  void execute() override;
  void fillStateOption() override;
};

} // namespace controller
