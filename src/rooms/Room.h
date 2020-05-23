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
 * @brief Room has an inventory of "dropped" items.csv, a list of npcs and linked rooms.
 */
class Room {
public:
  Room(const std::string &name, const std::string &description) : name(name), description(description) {
  }

  Room &add(const Character &npc) {
    npcs.emplace_back(npc);
    return *this;
  }

  Room &add(const Item &item, uint8_t quantity = 1) {
    inventory.addItem(item, quantity);
    return *this;
  }

  Room &addLink(const uint8_t &adjacentRoom) {
    adjacentRooms.insert(adjacentRoom);
    return *this;
  }

  bool hasNpc(const std::string npcType) {
    const auto res = std::find_if(npcs.begin(), npcs.end(), [npcType](Character npc) { return npcType == npc.name; });

    return (res != npcs.end());
  }

  friend std::ostream &operator<<(std::ostream &os, const Room &room);

  std::string name;
  std::string description;
  Inventory inventory;
  std::set<uint8_t> adjacentRooms;
  std::vector<Character> npcs;
};
