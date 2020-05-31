//
// Created by nolasco on 13/05/20.
//

#include "Generators.h"

#include <magic_enum.hpp>

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
  uint8_t duration;
  if (UseType::consume == useType) {
    duration = MathUtils::random(1, 10);
  } else if (UseType::equip == useType) {
    duration = MathUtils::random(20, 50);
  }
  Effect characterProperty = toEffect(items[itemSeed][3]);

  Item item = Item(items[itemSeed][0], items[itemSeed][1], characterProperty, useType, duration, modifierValue, price);
  return item;
}

Character createNPC() {
  uint8_t npcsAvailable = npcs.size();
  uint8_t characterSeed = MathUtils::random(1, npcsAvailable - 1);

  uint8_t namesAvailable = names.size();
  uint8_t nameSeed = MathUtils::random(1, namesAvailable - 1);

  uint8_t health = MathUtils::random(1, 10);
  uint8_t attack = MathUtils::random(1, 3);
  uint8_t defense = MathUtils::random(1, 5);
  uint8_t speed = MathUtils::random(1, 3);
  uint8_t money = MathUtils::random(1, 3);
  uint8_t experience = health + attack + defense + speed;

  Diplomacy diplomacy = toDiplomacy(npcs[characterSeed][3]);

  Properties properties{health, health, attack, defense, speed, money, experience};
  Character character = Character(names[nameSeed][0], npcs[characterSeed][0], npcs[characterSeed][1],
                                  npcs[characterSeed][2], properties, diplomacy);

  for (uint8_t it = 0; it < 2u; ++it) {
    character.add(createItem());
  }

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

  Properties properties{20u, 20u, 2u, 2u, 2u, 0u, 0u};
  world.player = Character{"Player",   "No idea",          "Help me, get to the end of the maze!", "You've failed me!",
                           properties, Diplomacy::friendly};
  for (uint8_t it = 0; it < 3u; ++it) {
    world.player.add(generator::createItem());
  }

  return world;
}

Effect toEffect(std::string fromFile) {
  const auto effect = magic_enum::enum_cast<Effect>(fromFile);
  if (effect.has_value()) {
    return effect.value();
  } else {
    std::cerr << "Invalid effect " << fromFile << ". Using default attack" << std::endl;
    return Effect::attack;
  }
}

UseType toUseType(std::string fromFile) {
  const auto useType = magic_enum::enum_cast<UseType>(fromFile);
  if (useType.has_value()) {
    return useType.value();
  } else {
    std::cerr << "Invalid use type " << fromFile << ". Using default consume" << std::endl;
    return UseType::consume;
  }
}

Diplomacy toDiplomacy(std::string fromFile) {
  const auto diplomacy = magic_enum::enum_cast<Diplomacy>(fromFile);
  if (diplomacy.has_value()) {
    return diplomacy.value();
  } else {
    std::cerr << "Invalid diplomacy " << fromFile << ". Using default friendly" << std::endl;
    return Diplomacy::friendly;
  }
}

} // namespace generator
