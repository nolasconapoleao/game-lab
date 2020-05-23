//
// Created by nolasco on 13/05/20.
//

#pragma once

#include "characters/Character.h"
#include "items/Item.h"
#include "utils/MathUtils.h"

/**
 * @brief Use or equip item on a character.
 * @param character that gets equipped/ consumes item
 * @param item that is consumed/ eqquiped
 */
void entityUseItem(Character &character, const Item &item);

/**
 * @brief Send item with itemId from origin to destination inventories.
 * @param origin inventory
 * @param destination inventory
 * @param itemId that identifies the item
 */
void exchangeItem(Inventory &origin, Inventory &destination, uint8_t itemId, uint8_t quantity = 1);
