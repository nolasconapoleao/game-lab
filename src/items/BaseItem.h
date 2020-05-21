//
// Created by nolasco on 11/05/20.
//

#pragma once

#include <ostream>
#include <string>

/**
 * @brief Character property that is affected by the item.
 */
enum class CharacterProperty {
  maxHealth,
  currentHealth,
  attack,
};

/**
 * @brief Item use type.
 */
enum class UseType { equipable, consumable };

/**
 * @brief Base Item.
 */
class BaseItem {
public:
  BaseItem(const std::string &name, const std::string &description, CharacterProperty modifier, UseType useType,
           uint modifierValue, uint price)
      : name(name), description(description), modifier(modifier), useType(useType), modifierValue(modifierValue),
        price(price){};

  std::string name;
  std::string description;
  CharacterProperty modifier;
  UseType useType;
  uint modifierValue;
  uint price;
};
