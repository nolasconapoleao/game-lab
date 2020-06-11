//
// Created by nolasco on 07/06/20.
//

#include "Tutorial.h"

#include "controller/Controller.h"

enum STATES : StateId {
  ENTER_NAME = 1,
  WRONG_ANSWER,
  INPUT_ANYKEY,
};

namespace model::state {

Tutorial::Tutorial() : attempts(0) {
  failOutput.emplace_back("Let's start over. Say it with me 'any key'");
  failOutput.emplace_back("Enter 'any key' to start ..");
  failOutput.emplace_back("You truly are a rebel, but this is not the time.");
  failOutput.emplace_back("I can do this all day..");

  addState(ENTER_NAME, "Enter name");
  addState(WRONG_ANSWER, "Wrong answer");
  addState(INPUT_ANYKEY, "Input 'any key'");

  addTransition(STATE_STANDBYE, ENTER_NAME, 's');
  addTransition(ENTER_NAME, INPUT_ANYKEY, 'b');
  addTransition(INPUT_ANYKEY, WRONG_ANSWER, 'c');
  addTransition(WRONG_ANSWER, INPUT_ANYKEY, 'd');
  addTransition(INPUT_ANYKEY, STATE_STANDBYE, 'e');
}

void Tutorial::start() {
  triggerTransition('s');
}

void Tutorial::whatsUp() {

  switch (activeState) {

    case ENTER_NAME: {
      mPrinter.directPrint("What is your name?");
      name = controller::readSentence();
      mPrinter.clearScreen();
      mPrinter.directPrint("Hey there, " + name);

      triggerTransition('b');
      break;
    }

    case INPUT_ANYKEY: {
      mPrinter.directPrint("Enter any key to start ..");

      std::string input = controller::readSentence();

      if ("any key" == input) {
        triggerTransition('e');
      } else {
        triggerTransition('c');
        attempts++;
        attempts %= failOutput.size();
      }
      break;
    }

    case WRONG_ANSWER: {
      mPrinter.directPrint(failOutput[attempts]);

      triggerTransition('d');
      break;
    }
  }
}

} // namespace model::state
