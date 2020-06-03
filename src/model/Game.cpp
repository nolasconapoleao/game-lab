//
// Created by nolasco on 02/06/20.
//

#include "Game.h"

#include "controller/Controller.h"

namespace model {

Game::Game() : mTerminateGame(false) {
  init();
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

  const auto alphaNum = controller::Controller::readAlphaNumeric(5);
  mPrinter.addToRoundReport(Verbose::INFO, "Very well");

  mPrinter.clearScreen();

  if ('x' == alphaNum) {
    mTerminateGame = true;
  }
}

void Game::init() {
  mPrinter.addToHud(Verbose::INFO, "What is your name?");
  mPrinter.printHud();

  const auto name = controller::Controller::readSentence();
  mPrinter.addToRoundReport(Verbose::INFO, "Hey " + name);
  mPrinter.printRoundReport();
  mPrinter.addToHud(Verbose::INFO, "Enter any key to start ..");
  mPrinter.printHud();
  const auto key = controller::Controller::readSentence();
  mPrinter.addToRoundReport(Verbose::INFO, "Wrong!!");
}

} // namespace model
