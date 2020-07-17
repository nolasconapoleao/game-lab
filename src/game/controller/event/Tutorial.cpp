//
// Created by nolasco on 07/06/20.
//

#include "Tutorial.h"

namespace controller {

Tutorial::Tutorial(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer, int8_t exitScore)
    : KingCrab(isMaze, difficulty, eventOriginer, exitScore) {
  failOutput.emplace_back("Let's start over. Say it with me 'any key'");
  failOutput.emplace_back("I mean 'any key'");
  failOutput.emplace_back("You truly are a rebel, but this is not the time.");
  failOutput.emplace_back("I can do this all day..");

  std::vector<std::pair<std::string, Score>> alternatives;
  alternatives.emplace_back("any key", 1);
  Platform platform1{"Enter any key to start ..", alternatives};
  mKingCrab.emplace_back(platform1);

  createNetwork();
}

void Tutorial::punish() {
  view::Printer::directPrint(failOutput[mAccumulatedScore %= failOutput.size()]);
  mHandler.changePlayerName(World::activeCharacter, "Looser");
}

void Tutorial::reward() {
  mHandler.changePlayerName(World::activeCharacter, "The champion");
}

} // namespace controller
