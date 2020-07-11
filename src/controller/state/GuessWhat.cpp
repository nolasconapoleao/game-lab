//
// Created by nolasco on 11/07/20.
//

#include "GuessWhat.h"

namespace controller {
GuessWhat::GuessWhat(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer)
    : KingCrab(isMaze, difficulty, eventOriginer) {
  std::vector<std::pair<std::string, Score>> alternatives;
  alternatives.emplace_back("What?", 0);
  alternatives.emplace_back("Who's there?", 1);
  alternatives.emplace_back("I already know this one.", -1);
  Platform platform1{"Guess what?", alternatives};
  mKingCrab.emplace_back(platform1);

  alternatives.clear();
  alternatives.emplace_back("Chicken Soup?!", -1);
  alternatives.emplace_back("Backed potatoes.", 1);
  alternatives.emplace_back("Force field are always there for you.", 0);
  Platform platform2{"Chicken Soup", alternatives};
  mKingCrab.emplace_back(platform2);

  createNetwork();
}

void GuessWhat::punish() {
  mHandler.changePlayerName(World::activeCharacter, "Looser");
}

void GuessWhat::reward() {
  mHandler.changePlayerName(World::activeCharacter, "The champion");
}

} // namespace controller
