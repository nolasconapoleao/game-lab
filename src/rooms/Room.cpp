//
// Created by nolasco on 10/05/20.
//

#include "Room.h"

Room::Room(const std::string &name, const std::string &description) : name(name), description(description) {
}

Room &Room::add(const Character &npc) {
  npcs.emplace_back(npc);
  return *this;
}

Room &Room::add(const Item &item, uint8_t quantity) {
  inventory.addItem(item, quantity);
  return *this;
}

Room &Room::addLink(const uint8_t &adjacentRoom) {
  adjacentRooms.insert(adjacentRoom);
  return *this;
}

bool Room::hasNpc(const std::string npcClass) {
  const auto res
      = std::find_if(npcs.begin(), npcs.end(), [npcClass](Character npc) { return npcClass == npc.charClass; });

  return (res != npcs.end());
}
