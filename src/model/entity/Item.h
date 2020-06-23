//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "model/entity/include/ItemEffect.h"
#include "model/entity/include/ItemOwnerType.h"
#include "model/entity/include/ItemOwnership.h"
#include "model/entity/include/UseType.h"

namespace entity {

class Item {
public:
  Item(std::string name, UseType useType, Number weight, const ItemEffect &effect);
  Number getQuantity() const;
  void setQuantity(Number quantity);
  const ItemOwnership &getOwnership() const;
  void setOwnership(const ItemOwnership &ownership);
  UseType getUseType() const;
  Number getWeight() const;
  const ItemEffect &getEffect() const;

  friend std::string minimalPrint(const Item &value);
  friend std::string fullPrint(const Item &value);

private:
  std::string name;
  UseType useType;
  Number weight;
  Number quantity;
  ItemEffect effect;
  ItemOwnership ownership;
};

} // namespace entity
