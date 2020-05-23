//
// Created by nolasco on 10/05/20.
//

#include "Player.h"

Player::Player()
    : Character("Player", "Help me, get to the end of the maze!", "You've failed me!", 20, 3, Diplomacy::friendly) {
  properties.money = 30;
};
