//
// Created by nolasco on 29/06/20.
//

#pragma once

#include "game/controller/state/include/Caterpillar.h"

namespace controller {

class Attack : public Caterpillar {
public:
  Attack();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace controller
