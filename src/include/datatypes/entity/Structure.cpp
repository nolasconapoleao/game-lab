//
// Created by nolasco on 20/06/20.
//

#include "Structure.h"

#include "interface/entity/Entity.h"

namespace entity {

Structure::Structure(const std::string &name, StructureType type, const Size &size)
    : Entity(name), type(type), size(size), health(size.height * size.width) {
}

} // namespace entity
