//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "characters/Character.h"

/**
 * @brief Room has a floor with spoils, a list of npcs and linked rooms.
 */
class Room {
public:
  Room(const std::string &name, const std::string &description);
  Room &add(const Character &npc);
  Room &add(const Item &item, uint8_t quantity = 1);
  Room &addLink(const uint8_t &adjacentRoom);
  bool hasNpc(const std::string npcClass);

  std::string name;
  std::string description;
  Inventory floor;
  std::set<uint8_t> adjacentRooms;
  std::vector<Character> npcs;
};
