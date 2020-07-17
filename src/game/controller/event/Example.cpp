//
// Created by nolasco on 11/06/20.
//

#include "Example.h"

namespace controller {

Example::Example(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer, int8_t exitScore)
    : KingCrab(isMaze, difficulty, eventOriginer, exitScore) {
  std::vector<std::pair<std::string, Score>> alternatives;
  alternatives.emplace_back("a", 1);
  alternatives.emplace_back("b", -1);
  alternatives.emplace_back("c", -1);
  Platform platform1{"Gimme an a", alternatives};
  mKingCrab.emplace_back(platform1);

  alternatives.clear();
  alternatives.emplace_back("a", -1);
  alternatives.emplace_back("b", 1);
  alternatives.emplace_back("c", -1);
  Platform platform2{"What comes after a?", alternatives};
  mKingCrab.emplace_back(platform2);

  createNetwork();
}

void Example::punish() {
  mHandler.changePlayerName(World::activeCharacter, "Loooser");
}

void Example::reward() {
  mHandler.changePlayerName(World::activeCharacter, "Spelling king");
}

} // namespace controller
