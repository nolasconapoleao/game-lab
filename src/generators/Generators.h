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
Room createRoom(uint8_t roomsInWorld, uint8_t roomIndex);

/**
 * @brief Generate world with connections of rooms, npcs and items.
 */
World createWorld(uint8_t dificulty = 1);

Effect toEffect(std::string fromFile);
UseType toUseType(std::string fromFile);
Diplomacy toDiplomacy(std::string fromFile);

} // namespace generator
