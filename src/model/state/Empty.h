//
// Created by nolasco on 27/06/20.
//

#pragma once

#include "model/state/include/Caterpillar.h"

namespace model::state {

class Empty : public Caterpillar {
public:
  Empty();
  void execute() override;

protected:
  void fillStateOption() override;
};

} // namespace model::state