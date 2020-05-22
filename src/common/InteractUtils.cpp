//
// Created by nolasco on 13/05/20.
//

#include "characters/Character.h"
#include "items/Item.h"
#include "utils/MathUtils.h"

/**
 * @brief Use or equip item on a character.
 * @param character that gets equipped/ consumes item
 * @param item that is consumed/ eqquiped
 */
inline void entityUseItem(Character &character, const Item &item) {
  switch (item.modifier) {
    case Effect::health:
      character.properties.health
          = MathUtils::clamp_add(character.properties.health, item.modifierValue, character.properties.maxHealth);
      break;
    case Effect::attack:
      character.properties.attack = MathUtils::clamp_add(character.properties.attack, item.modifierValue, 1e3);
      break;
    case Effect::maxHealth:
      character.properties.maxHealth = MathUtils::clamp_add(character.properties.maxHealth, item.modifierValue, 1e3);
      break;
  }
}

/**
 * @brief Send item with itemId from origin to destination inventories.
 * @param origin inventory
 * @param destination inventory
 * @param itemId that identifies the item
 */
inline void exchangeItem(Inventory &origin, Inventory &destination, uint8_t itemId, uint8_t quantity = 1) {
  auto consumableEntry = std::find_if(origin.consumables.begin(), origin.consumables.end(),
                                      [itemId](ConsumableEntry entry) { return itemId == entry.itemId; });
  if (consumableEntry != origin.consumables.end()) {
    destination.addItem(consumableEntry->item, consumableEntry->quantity);
    origin.consumeItem(itemId);
  }

  auto equipableEntry = std::find_if(origin.equipables.begin(), origin.equipables.end(),
                                     [itemId](EquipableEntry entry) { return itemId == entry.itemId; });
  if (equipableEntry != origin.equipables.end()) {
    destination.addItem(equipableEntry->item);
    origin.dropItem(itemId);
  }
}
