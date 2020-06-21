//
// Created by nolasco on 07/06/20.
//

#include "ItemFactory.h"

#include "utils/random/Random.h"

ItemFactory::ItemFactory() {
  // Single Use
  singleUsePool.emplace_back(ItemPrototype::POTION);

  // Equip
  equipPool.emplace_back(ItemPrototype::SWORD);
  equipPool.emplace_back(ItemPrototype::SHIELD);
}

entity::Item ItemFactory::generateItem(UseType useType) {
  // TODO: [nn] Change access to random element of vector
  std::vector<ItemPrototype>::iterator itemType;

  switch (useType) {
    case UseType::equip:
      itemType = equipPool.begin();
      std::advance(itemType, Random::fromTo(0,equipPool.size()-1));
      break;
    case UseType::singleUse:
      itemType = singleUsePool.begin();
      std::advance(itemType, Random::fromTo(0,singleUsePool.size()-1));
      break;
  }
  return createItem(*itemType);
}

entity::Item ItemFactory::createItem(ItemPrototype type) {
  // TODO: replace by random generation based on item type
  entity::ItemEffect effect{2, 3, 1, 0};

  switch (type) {
    case ItemPrototype::POTION:
      effect.hp = 8;
      return entity::Item(UseType::singleUse, 1, effect);
    case ItemPrototype::SWORD:
      effect.atk = 6;
      return entity::Item(UseType::equip, 15, effect);
    case ItemPrototype::SHIELD:
      effect.def = 4;
      return entity::Item(UseType::equip, 8, effect);
  }
}
