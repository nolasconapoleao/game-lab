//
// Created by nolasco on 21/05/20.
//

#include "characters/BaseCharacter.h"
//#include "items/BaseItem.h"
#include "rooms/World.h"
#include "utils/FileUtils.h"

namespace generator {

///**
// * @brief Generate character with items.
// */
// void createNPC();

/**
 * @brief Generate room with npcs.
 */
Room createRoom(uint roomsInWorld, uint roomIndex);

/**
 * @brief Generate world with connections of rooms, npcs and items.
 */
World createWorld(uint dificulty = 1);
} // namespace generator
