//
// Created by nolasco on 22/05/20.
//

#include "InteractUtils.h"

constexpr uint8_t c_maxValue = 255;

void entityUseItem(Character &character, const Item &item) {
  switch (item.modifier) {
    case Effect::health:
      character.properties.health
          = MathUtils::clamp_add(character.properties.health, item.modifierValue, character.properties.maxHealth);
      break;
    case Effect::attack:
      character.properties.attack = MathUtils::clamp_add(character.properties.attack, item.modifierValue, c_maxValue);
      break;
    case Effect::maxHealth:
      character.properties.maxHealth
          = MathUtils::clamp_add(character.properties.maxHealth, item.modifierValue, c_maxValue);
      break;
    case Effect::defense:
      character.properties.defense = MathUtils::clamp_add(character.properties.defense, item.modifierValue, c_maxValue);
      break;
  }
}

void exchangeItem(Inventory &origin, Inventory &destination, uint8_t itemId, uint8_t quantity) {
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
