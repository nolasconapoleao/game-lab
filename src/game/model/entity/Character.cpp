//
// Created by nolasco on 07/06/20.
//

#include "Character.h"

namespace entity {

Character::Character(const std::string &name, const Stats &baseStats, const Info &info)
    : Entity(name), baseStats(baseStats), info(info) {
}

} // namespace entity
