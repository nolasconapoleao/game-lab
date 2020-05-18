//
// Created by nolasco on 13/05/20.
//

#pragma once

#include "characters/BaseCharacter.h"
#include "items/BaseItem.h"

/**
 * @brief Use or equip item on a character.
 * @param character that gets equipped/ consumes item
 * @param item that is consumed/ eqquiped
 */
void entityUseItem(BaseCharacter &character, const std::shared_ptr<BaseItem> &item);
