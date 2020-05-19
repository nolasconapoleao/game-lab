//
// Created by nolasco on 19/05/20.
//

#include "Shopkeeper.h"

Shopkeeper::Shopkeeper() : BaseCharacter("Shopkeeper", 20, 3, CharacterRelation::neutral){};

std::string Shopkeeper::sayHi() {
  return "Hey, sup traveller what can I get you?";
}

std::string Shopkeeper::sayBye() {
  return "Thank you for your business";
}
