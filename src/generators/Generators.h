//
// Created by nolasco on 21/05/20.
//

#include "characters/Character.h"
#include "rooms/World.h"
#include "utils/FileUtils.h"

namespace generator {
/**
 * @brief Generate item.
 */
Item createItem();

/**
 * @brief Generate character with items.
 */
Character createNPC();

/**
 * @brief Generate room with npcs.
 */
Room createRoom(uint roomsInWorld, uint roomIndex);

/**
 * @brief Generate world with connections of rooms, npcs and items.
 */
World createWorld(uint dificulty = 1);

Effect toCharacterProperty(std::string fromFile);
UseType toUseType(std::string fromFile);
Diplomacy toCharacterRelation(std::string fromFile);

} // namespace generator
