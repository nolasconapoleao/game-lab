//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>

class BaseRoom {
public:
  BaseRoom(const std::string &description) : description(description) {
  }

  void setAdjacentRooms(const std::vector<std::shared_ptr<BaseRoom>> &adjacentRooms) {
    BaseRoom::adjacentRooms = adjacentRooms;
  }

  friend std::ostream &operator<<(std::ostream &os, const BaseRoom &room) {
    os << room.description;
    return os;
  }

  std::string description;
  std::vector<std::shared_ptr<BaseRoom>> adjacentRooms;
  std::vector<std::shared_ptr<BaseCharacter>> npcs;
};
