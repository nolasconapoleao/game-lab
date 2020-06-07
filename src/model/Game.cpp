//
// Created by nolasco on 02/06/20.
//

#include "Game.h"

#include "controller/Controller.h"

namespace model {

Game::Game() : mTerminateGame(false) {
  init();
}

Game::~Game() {
  shutdown();
}

const bool Game::isOver() {
  return mTerminateGame;
}

void Game::loop() {
  mPrinter.addToOptions(Verbose::INFO, "Enter a value between 1 and 5, or a base option (x,m):");

  mPrinter.printRoundReport();
  mPrinter.printScene();
  mPrinter.printHud();
  mPrinter.printOptions();

  std::string options = "12345";
  const auto alphaNum = controller::readAlphaNum(options);
  mPrinter.addToRoundReport(Verbose::INFO, "Very well");

  if ('x' == alphaNum) {
    mTerminateGame = true;
    return;
  }

  mPrinter.clearScreen();
}

void Game::init() {
  playerInfo();
  gameTutorial();
}

void Game::playerInfo() {
  mPrinter.directPrint("What is your name?");

  const auto name = controller::readSentence();
  mPrinter.clearScreen();
  mPrinter.directPrint("Hey " + name);
}

void Game::gameTutorial() {
  mPrinter.directPrint("Enter any key to start ..");
  auto key = controller::readSentence();

  if ("any key" == key) {
    return;
  }

  mPrinter.directPrint("Wrong!!");
  mPrinter.directPrint("Enter 'any key' to start ..");
  key = controller::readSentence();

  mPrinter.clearScreen();
  mPrinter.directPrint("any key" == key ? "Good!" : "Whatever.");
}

void Game::shutdown() {
  mPrinter.directPrint("Game over.");
}

} // namespace model
