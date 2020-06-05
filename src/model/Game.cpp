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

  const auto alphaNum = controller::readAlphaNumeric(5);
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
  mPrinter.addToHud(Verbose::INFO, "What is your name?");
  mPrinter.printHud();

  const auto name = controller::readSentence();
  mPrinter.clearScreen();
  mPrinter.addToRoundReport(Verbose::INFO, "Hey " + name);
  mPrinter.printRoundReport();
}

void Game::gameTutorial() {
  mPrinter.addToHud(Verbose::INFO, "Enter any key to start ..");
  mPrinter.printHud();
  auto key = controller::readSentence();

  if ("any key" == key) {
    return;
  }

  mPrinter.addToRoundReport(Verbose::INFO, "Wrong!!");
  mPrinter.addToRoundReport(Verbose::INFO, "Enter 'any key' to start ..");
  mPrinter.printRoundReport();
  key = controller::readSentence();

  mPrinter.clearScreen();
  mPrinter.addToRoundReport(Verbose::INFO, "any key" == key ? "Good!" : "Whatever.");
  mPrinter.printRoundReport();
}

void Game::shutdown() {
  mPrinter.addToRoundReport(Verbose::INFO, "Game over.");
  mPrinter.printRoundReport();
}

} // namespace model
