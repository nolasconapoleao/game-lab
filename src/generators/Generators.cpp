//
// Created by nolasco on 13/05/20.
//

#include "Generators.h"

#include "utils/MathUtils.h"

namespace generator {
std::vector<std::vector<std::string>> rooms = CSVReader("../databases/rooms.csv").getData();
std::vector<std::vector<std::string>> names = CSVReader("../databases/names.csv").getData();
std::vector<std::vector<std::string>> npcs = CSVReader("../databases/npcs.csv").getData();
std::vector<std::vector<std::string>> items = CSVReader("../databases/items.csv").getData();

Item createItem() {
  uint itemsAvailable = items.size();
  uint itemSeed = MathUtils::random(1, itemsAvailable - 1);

  uint modifierValue = MathUtils::random(1, 3);
  uint price = MathUtils::random(1, 10);

  // TODO: use type and character property should defined in the csv file
  UseType useType = UseType::consumable;
  CharacterProperty characterProperty = CharacterProperty::attack;

  Item item = Item(items[itemSeed][0], items[itemSeed][1], characterProperty, useType, modifierValue, price);
  return item;
}

Character createNPC() {
  uint npcsAvailable = npcs.size();
  uint characterSeed = MathUtils::random(1, npcsAvailable - 1);

  uint attack = MathUtils::random(1, 3);
  uint health = MathUtils::random(1, 10);

  // TODO: diplomacy should be calculated based on class
  CharacterRelation diplomacy = CharacterRelation::hostile;

  Character character
      = Character(names[characterSeed][0], npcs[characterSeed][1], npcs[characterSeed][2], health, attack, diplomacy);
  return character;
}

Room createRoom(uint roomsInWorld, uint roomIndex) {
  uint availableRoms = rooms.size();
  uint roomSeed = MathUtils::random(1, availableRoms - 1);

  Room room = Room(rooms[roomSeed][0], rooms[roomSeed][1]);
  for (uint id = 0; id < 3u; ++id) {
    uint adjacentRoomSeed = MathUtils::random(0, roomsInWorld - 1);

    // Room should not link to itself
    if (adjacentRoomSeed != roomIndex) {
      room.addLink(adjacentRoomSeed);
    }
  }

  for (uint it = 0; it < 2u; ++it) {
    room.add(createNPC());
    room.add(createItem());
  }

  return room;
}

/**
 * @brief Generate world with connections of rooms, npcs and items.csv.
 */
World createWorld(uint dificulty) {
  World world;
  uint roomsInWorld = 4 * dificulty + 1;

  for (uint id = 0; id < roomsInWorld; ++id) {
    world.add(createRoom(roomsInWorld, id));
  }

  return world;
}

} // namespace generator
