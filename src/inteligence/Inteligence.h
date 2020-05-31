//
// Created by nolasco on 25/05/20.
//

#pragma once

#include <rooms/World.h>

#include "rooms/Room.h"

class Inteligence {
public:
  static void smallBrain(Character &bot, World &world, std::vector<std::string> &convos);

private:
  static void think(Character &bot, World &world, std::vector<std::string> &convos, uint8_t decision);
};
