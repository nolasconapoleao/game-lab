//
// Created by nolasco on 20/06/20.
//

#include "Structure.h"

#include "interface/entity/Entity.h"

namespace entity {

Structure::Structure(const std::string &name, const Size &size) : Entity(name), size(size) {
}

} // namespace entity
