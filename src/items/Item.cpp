//
// Created by nolasco on 11/05/20.
//

#include "Item.h"

Item::Item(const std::string &name, const std::string &description, Effect modifier, UseType useType, uint8_t uses,
           uint8_t modifierValue, uint8_t price)
    : name(name), description(description), effect(modifier), useType(useType), modifierValue(modifierValue),
      price(price), duration(uses){};
