//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <vector>

#include "model/entity/Structure.h"
#include "model/factory/include/StructurePrototype.h"

class StructureFactory {
public:
  StructureFactory();
  entity::Structure generateStructure();
  entity::Structure createStructure(const StructurePrototype type);

private:
  std::vector<StructurePrototype> structurePool;
};
