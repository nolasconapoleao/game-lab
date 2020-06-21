//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <vector>

#include "controller/factory/include/StructurePrototype.h"
#include "model/entity/Structure.h"

class StructureFactory {
public:
  StructureFactory();
  entity::Structure generateStructure();
  entity::Structure createStructure(const StructurePrototype type);

private:
  std::vector<StructurePrototype> structurePool;
};
