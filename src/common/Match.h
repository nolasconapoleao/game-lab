//
// Created by nolasco on 24/05/20.
//

#pragma once
#include <characters/Character.h>

enum class AttackResult {
  Fail,
  Hit,
  Critical,
};

struct MatchResult {
  AttackResult attacker = AttackResult::Fail;
  AttackResult attacked = AttackResult::Fail;
  bool attackerDied = false;
  bool attackedDied = false;
  bool diplomacyUpdate = false;
};

class Match {
public:
  [[nodiscard]] static const MatchResult match(Character &attacked, Character &attacker,
                                               const bool attackedRetaliates = false);

private:
  [[nodiscard]] const static AttackResult attack(Character &attacked, const Character &attacker);
};
