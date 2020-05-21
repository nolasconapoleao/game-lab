//
// Created by nolasco on 13/05/20.
//

#include "characters/Character.h"
#include "items/BaseItem.h"
#include "utils/MathUtils.h"

/**
 * @brief Use or equip item on a character.
 * @param character that gets equipped/ consumes item
 * @param item that is consumed/ eqquiped
 */
inline void entityUseItem(Character &character, const std::shared_ptr<BaseItem> &item) {
  switch (item->modifier) {
    case CharacterProperty::currentHealth:
      character.properties.currentHealthPoints = MathUtils::clamp_add(
          character.properties.currentHealthPoints, item->modifierValue, character.properties.maxHealthPoints);
      break;
    case CharacterProperty::attack:
      character.properties.attackPoints
          = MathUtils::clamp_add(character.properties.attackPoints, item->modifierValue, 1e3);
      break;
    case CharacterProperty::maxHealth:
      character.properties.maxHealthPoints
          = MathUtils::clamp_add(character.properties.maxHealthPoints, item->modifierValue, 1e3);
      break;
  }
}

/**
 * @brief Send item with itemId from origin to destination inventories.
 * @param origin inventory
 * @param destination inventory
 * @param itemId that identifies the item
 */
inline void exchangeItem(Inventory &origin, Inventory &destination, uint itemId, uint quantity = 1) {
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
