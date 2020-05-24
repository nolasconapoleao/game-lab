//
// Created by nolasco on 11/05/20.
//

#pragma once

#include <ostream>
#include <string>

/**
 * @brief Character property that is affected by the item.
 */
enum class Effect {
  maxHealth,
  health,
  attack,
  defense,
};

/**
 * @brief Item use type.
 */
enum class UseType { equip, consume };

/**
 * @brief Item.
 */
class Item {
public:
  Item(const std::string &name, const std::string &description, Effect modifier, UseType useType, uint8_t uses,
       uint8_t modifierValue, uint8_t price);

  std::string name;
  std::string description;
  Effect effect;
  UseType useType;
  uint8_t duration;
  uint8_t modifierValue;
  uint8_t price;
};
