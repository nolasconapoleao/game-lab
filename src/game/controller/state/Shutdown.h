//
// Created by nolasco on 21/06/20.
//

#pragma once

#include "interface/state/Caterpillar.h"

namespace controller {

class Shutdown : public Caterpillar {
public:
  Shutdown();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace controller
