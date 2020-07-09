//
// Created by nolasco on 27/06/20.
//

#pragma once

#include "controller/state/include/Caterpillar.h"

namespace controller {

class Empty : public Caterpillar {
public:
  Empty();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace controller