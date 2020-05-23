//
// Created by nolasco on 13/05/20.
//

#include "Generators.h"

#include "utils/MathUtils.h"

namespace generator {
std::vector<std::vector<std::string>> rooms = CSVReader("res/rooms.csv").getData();
std::vector<std::vector<std::string>> names = CSVReader("res/names.csv").getData();
std::vector<std::vector<std::string>> npcs = CSVReader("res/npcs.csv").getData();
std::vector<std::vector<std::string>> items = CSVReader("res/items.csv").getData();

Item createItem() {
  uint8_t itemsAvailable = items.size();
  uint8_t itemSeed = MathUtils::random(1, itemsAvailable - 1);

  uint8_t modifierValue = MathUtils::random(1, 3);
  uint8_t price = MathUtils::random(1, 10);

  UseType useType = toUseType(items[itemSeed][2]);
  Effect characterProperty = toCharacterProperty(items[itemSeed][3]);

  Item item = Item(items[itemSeed][0], items[itemSeed][1], characterProperty, useType, modifierValue, price);
  return item;
}

Character createNPC() {
  uint8_t npcsAvailable = npcs.size();
  uint8_t characterSeed = MathUtils::random(1, npcsAvailable - 1);

  uint8_t namesAvailable = names.size();
  uint8_t nameSeed = MathUtils::random(1, namesAvailable - 1);

  uint8_t attack = MathUtils::random(1, 3);
  uint8_t health = MathUtils::random(1, 10);

  Diplomacy diplomacy = toCharacterRelation(npcs[characterSeed][3]);

  Character character
      = Character(names[nameSeed][0], npcs[characterSeed][1], npcs[characterSeed][2], health, attack, diplomacy);
  return character;
}

Room createRoom(uint8_t roomsInWorld, uint8_t roomIndex) {
  uint8_t availableRoms = rooms.size();
  uint8_t roomSeed = MathUtils::random(1, availableRoms - 1);

  Room room = Room(rooms[roomSeed][0], rooms[roomSeed][1]);
  for (uint8_t id = 0; id < 3u; ++id) {
    uint8_t adjacentRoomSeed = MathUtils::random(0, roomsInWorld - 1);

    // Room should not link to itself
    if (adjacentRoomSeed != roomIndex) {
      room.addLink(adjacentRoomSeed);
    }
  }

  for (uint8_t it = 0; it < 2u; ++it) {
    room.add(createNPC());
    room.add(createItem());
  }

  return room;
}

/**
 * @brief Generate world with connections of rooms, npcs and items.csv.
 */
World createWorld(uint8_t dificulty) {
  World world;
  uint8_t roomsInWorld = 4 * dificulty + 1;

  for (uint8_t id = 0; id < roomsInWorld; ++id) {
    world.add(createRoom(roomsInWorld, id));
  }

  return world;
}

Effect toCharacterProperty(std::string fromFile) {
  if ("attack" == fromFile) {
    return Effect::attack;
  } else if ("health" == fromFile) {
    return Effect::health;
  } else if ("maxHealth" == fromFile) {
    return Effect::maxHealth;
  } else if ("defense" == fromFile) {
    return Effect::defense;
  }
}

UseType toUseType(std::string fromFile) {
  if ("consume" == fromFile) {
    return UseType::consumable;
  } else if ("equip" == fromFile) {
    return UseType::equipable;
  }
}

Diplomacy toCharacterRelation(std::string fromFile) {
  if ("hostile" == fromFile) {
    return Diplomacy::hostile;
  } else if ("neutral" == fromFile) {
    return Diplomacy::neutral;
  } else if ("friend" == fromFile) {
    return Diplomacy::friendly;
  }
}

} // namespace generator
