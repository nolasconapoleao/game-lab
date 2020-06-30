//
// Created by nolasco on 29/06/20.
//

#pragma once

#include "model/state/include/Caterpillar.h"

namespace model::state {

class Attack : public Caterpillar {
public:
  Attack();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace model::state
