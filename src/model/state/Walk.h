//
// Created by nolasco on 24/06/20.
//

#pragma once

#include "model/state/include/Caterpillar.h"

namespace model::state {

class Walk : public Caterpillar {
public:
  Walk();

private:
  void execute() override;
  void fillStateOption() override;
};

} // namespace model::state
