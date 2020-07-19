//
// Created by nolasco on 29/06/20.
//

#pragma once

#include "interface/state/Caterpillar.h"

namespace controller {

class Attack : public Caterpillar {
public:
  Attack();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace controller
