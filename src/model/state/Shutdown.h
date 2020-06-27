//
// Created by nolasco on 21/06/20.
//

#pragma once

#include "model/state/include/Caterpillar.h"

namespace model::state {

class Shutdown : public Caterpillar {
public:
  Shutdown();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace model::state
