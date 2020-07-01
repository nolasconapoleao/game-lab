//
// Created by nolasco on 07/06/20.
//

#include "Factory.h"
#include "utils/random/Random.h"

void Factory::addItem(entity::Item item) {
  world.addItem(item);
}

void Factory::generateItem(UseType useType) {
  // TODO: [nn] Change access to random element of vector
  std::vector<ItemPrototype>::iterator itemType;

  switch (useType) {
    case UseType::equip:
      itemType = equipPool.begin();
      std::advance(itemType, Random::fromTo(0, equipPool.size() - 1));
      break;
    case UseType::singleUse:
      itemType = singleUsePool.begin();
      std::advance(itemType, Random::fromTo(0, singleUsePool.size() - 1));
      break;
  }
  createItem(*itemType);
}

void Factory::createItem(ItemPrototype type) {
  // TODO: replace by random generation based on item type
  ItemEffect effect{2, 3, 1, 0};

  entity::Item creation;
  switch (type) {
    case ItemPrototype::POTION:
      effect.hp = 8;
      creation = entity::Item("Potion", UseType::singleUse, 1, effect);
      break;
    case ItemPrototype::SWORD:
      effect.atk = 6;
      creation = entity::Item("Sword", UseType::equip, 15, effect);
      break;
    case ItemPrototype::SHIELD:
      effect.def = 4;
      creation = entity::Item("Shield", UseType::equip, 8, effect);
      break;
  }

  addItem(creation);
}
