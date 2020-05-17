//
// Created by nolasco on 13/05/20.
//

#include "InteractUtils.h"

#include "utils/MathUtils.h"

void entityUseItem(BaseCharacter &character, const std::shared_ptr<BaseItem> &item) {
  switch (item->modifier) {
  case CharacterProperty::currentHealth:
    character.currentHealthPoints =
        MathUtils::clamp_add(character.currentHealthPoints, item->modifierValue, character.maxHealthPoints);
    break;
  case CharacterProperty::attack:
    character.attackPoints = MathUtils::clamp_add(character.attackPoints, item->modifierValue, 1e3);
    break;
  case CharacterProperty::maxHealth:
    character.maxHealthPoints = MathUtils::clamp_add(character.maxHealthPoints, item->modifierValue, 1e3);
    break;
  }
}
