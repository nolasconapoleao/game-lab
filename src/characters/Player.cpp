//
// Created by nolasco on 10/05/20.
//

#include "Player.h"

#include <wayland-egl.h>

Player::Player()
    : Character("Player", "Help me, get to the end of the maze!", "You've failed me!", 20, 3,
                CharacterRelation::friendly) {
  properties.money = 30;
};
