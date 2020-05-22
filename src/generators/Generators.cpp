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

  UseType useType = toUseType(items[itemSeed][2]);
  CharacterProperty characterProperty = toCharacterProperty(items[itemSeed][3]);

  Item item = Item(items[itemSeed][0], items[itemSeed][1], characterProperty, useType, modifierValue, price);
  return item;
}

Character createNPC() {
  uint npcsAvailable = npcs.size();
  uint characterSeed = MathUtils::random(1, npcsAvailable - 1);

  uint namesAvailable = names.size();
  uint nameSeed = MathUtils::random(1, namesAvailable - 1);

  uint attack = MathUtils::random(1, 3);
  uint health = MathUtils::random(1, 10);

  CharacterRelation diplomacy = toCharacterRelation(npcs[characterSeed][3]);

  Character character
      = Character(names[nameSeed][0], npcs[characterSeed][1], npcs[characterSeed][2], health, attack, diplomacy);
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

CharacterProperty toCharacterProperty(std::string fromFile) {
  if ("attack" == fromFile) {
    return CharacterProperty::attack;
  } else if ("health" == fromFile) {
    return CharacterProperty::currentHealth;
  } else if ("maxHealth" == fromFile) {
    return CharacterProperty::maxHealth;
  } else if ("defense" == fromFile) {
    return CharacterProperty::defense;
  }
}

UseType toUseType(std::string fromFile) {
  if ("consume" == fromFile) {
    return UseType::consumable;
  } else if ("equip" == fromFile) {
    return UseType::equipable;
  }
}

CharacterRelation toCharacterRelation(std::string fromFile) {
  if ("hostile" == fromFile) {
    return CharacterRelation::hostile;
  } else if ("neutral" == fromFile) {
    return CharacterRelation::neutral;
  } else if ("friend" == fromFile) {
    return CharacterRelation::friendly;
  }
}

} // namespace generator
