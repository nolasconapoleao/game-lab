//
// Created by nolasco on 07/06/20.
//

#include "Item.h"
namespace entity {

Item::Item(std::string name, UseType useType, Number weight, const ItemEffect &effect)
    : useType(useType), weight(weight), effect(effect) {
}

Number Item::getQuantity() const {
  return quantity;
}

void Item::setQuantity(Number quantity) {
  Item::quantity = quantity;
}

const ItemOwnership &Item::getOwnership() const {
  return ownership;
}

void Item::setOwnership(const ItemOwnership &ownership) {
  Item::ownership = ownership;
}

UseType Item::getUseType() const {
  return useType;
}

Number Item::getWeight() const {
  return weight;
}

const ItemEffect &Item::getEffect() const {
  return effect;
}

} // namespace entity
