//
// Created by nolasco on 07/06/20.
//

#include "Factory.h"
#include "random/Random.h"

void Factory::generateItem(UseType useType) {
  ItemPrototype typeId;
  std::vector<ItemPrototype>::iterator itemType;

  switch (useType) {
    case UseType::equip:
      typeId = Random::fromVec(equipPool);
      break;
    case UseType::singleUse:
      typeId = Random::fromVec(singleUsePool);
      break;
  }
  createItem(typeId);
}

void Factory::createItem(ItemPrototype type) {
  // TODO: replace by random generation based on item type
  ItemEffect effect{2, 3, 1, 0};

  entity::Item creation;
  Quantity quantity = 0;
  switch (type) {
    case ItemPrototype::POTION:
      effect.hp = 8;
      quantity = 5;
      creation = entity::Item("Potion", UseType::singleUse, 1, effect);
      break;
    case ItemPrototype::SWORD:
      effect.atk = 6;
      quantity = 50;
      creation = entity::Item("Sword", UseType::equip, 15, effect);
      break;
    case ItemPrototype::SHIELD:
      effect.def = 4;
      quantity = 50;
      creation = entity::Item("Shield", UseType::equip, 8, effect);
      break;
  }
  creation.setQuantity(quantity);
  World::addItem(creation);
}
