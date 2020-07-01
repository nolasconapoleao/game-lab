//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "model/state/include/Caterpillar.h"

namespace model::state {

class IdleWorld : public Caterpillar {
public:
  IdleWorld();
  void execute() override;

protected:
  void fillStateOption() override;
  Controller entityHandler;
};

} // namespace model::state
