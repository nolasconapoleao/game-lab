//
// Created by nolasco on 13/05/20.
//

#include "Generators.h"

#include "utils/MathUtils.h"

namespace generator {
CSVReader rooms = CSVReader("../databases/rooms.csv");

///**
// * @brief Generate character with items.
// */
// void createNPC() {
//  BaseCharacter character;
//}

/**
 * @brief Generate room with npcs.
 */
Room createRoom(uint roomsInWorld, uint roomIndex) {
  uint availableRoms = rooms.getData().size();
  uint roomSeed = MathUtils::random(1, availableRoms - 1);

  Room room = Room(rooms.getData()[roomSeed][0], rooms.getData()[roomSeed][1]);
  for (uint id = 0; id < 2; id++) {
    uint adjacentRoomSeed = MathUtils::random(0, roomsInWorld);

    // Room should not link to itself
    if (adjacentRoomSeed != roomIndex) {
      room.addLink(adjacentRoomSeed);
    }
  }

  return room;
}

/**
 * @brief Generate world with connections of rooms, npcs and items.
 */
World createWorld(uint dificulty) {
  World world;
  uint roomsInWorld = 4 * dificulty + 1;

  for (uint id = 0; id < roomsInWorld; id++) {
    world.add(std::make_shared<Room>(createRoom(roomsInWorld, id)));
  }

  return world;
}

} // namespace generator
