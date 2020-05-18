//
// Created by nolasco on 11/05/20.
//

#pragma once

#include <ostream>
#include <string>

/**
 * @brief Character property that is affected by the item.
 */
enum class CharacterProperty : u_int8_t {
  maxHealth = 0,
  currentHealth = 1,
  attack = 2,
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
  BaseItem(const std::string &name, CharacterProperty modifier, UseType useType, uint modifierValue)
      : name(name), modifier(modifier), useType(useType), modifierValue(modifierValue){};

  std::string name;
  CharacterProperty modifier;
  UseType useType;
  uint modifierValue;
};
