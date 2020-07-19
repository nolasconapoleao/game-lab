//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "datatypes/entity/ItemEffect.h"
#include "datatypes/entity/ItemOwnerType.h"
#include "datatypes/entity/ItemOwnership.h"
#include "datatypes/entity/UseType.h"

namespace entity {

class Item {
public:
  Item() = default;
  Item(std::string name, UseType useType, Number weight, const ItemEffect &effect);
  const std::string &getName() const;
  void setName(const std::string &name);
  Number getQuantity() const;
  void setQuantity(Number quantity);
  const ItemOwnership &getOwnership() const;
  void setOwnership(const ItemOwnership &ownership);
  UseType getUseType() const;
  Number getWeight() const;
  const ItemEffect &getEffect() const;

private:
  std::string name;
  UseType useType;
  Number weight;
  Number quantity;
  ItemEffect effect;
  ItemOwnership ownership;
};

} // namespace entity
