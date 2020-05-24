//
// Created by nolasco on 22/05/20.
//

#include "InteractUtils.h"

constexpr uint8_t c_maxValue = 255;

void entityUseItem(Character &character, const Item &item) {
  switch (item.effect) {
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
  auto entry = origin.entries.begin() + itemId;
  if (entry != origin.entries.end()) {
    destination.addItem(entry->item, entry->quantity);
    origin.dropItem(itemId, quantity);
  }
}
