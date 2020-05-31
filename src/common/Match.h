//
// Created by nolasco on 24/05/20.
//

#pragma once
#include <characters/Character.h>
#include <rooms/Room.h>

enum class AttackResult {
  Fail,
  Hit,
  Critical,
};

class Match {
public:
  static void match(Room &ring, Character &attacked, Character &attacker, std::vector<std::string> &convos);

private:
  [[nodiscard]] const static AttackResult attack(Character &attacked, const Character &attacker);
  static void dropAll(Room &ring, Character &deadCharacter);
};
