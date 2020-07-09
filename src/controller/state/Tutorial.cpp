//
// Created by nolasco on 07/06/20.
//

#include "Tutorial.h"

#include "controller/state/include/Substate.h"
#include "controller/state/include/Transition.h"
#include "input/Input.h"

enum STATES : StateId {
  ENTER_NAME = 1,
  WRONG_ANSWER,
  INPUT_ANYKEY,
};

namespace controller {

Tutorial::Tutorial() : attempts(0) {
  failOutput.emplace_back("Let's start over. Say it with me 'any key'");
  failOutput.emplace_back("I mean 'any key'");
  failOutput.emplace_back("You truly are a rebel, but this is not the time.");
  failOutput.emplace_back("I can do this all day..");

  addState(IDLE, "Macro state is in standbye");
  addState(TERMINATED, "Macro state was terminated");
  addState(ENTER_NAME, "Enter name");
  addState(WRONG_ANSWER, "Wrong answer");
  addState(INPUT_ANYKEY, "Input 'any key'");

  addTransition(IDLE, ENTER_NAME, START);
  addTransition(ENTER_NAME, INPUT_ANYKEY, 'b');
  addTransition(INPUT_ANYKEY, WRONG_ANSWER, 'c');
  addTransition(WRONG_ANSWER, INPUT_ANYKEY, 'd');
  addTransition(INPUT_ANYKEY, TERMINATED, 'e');
  addTransition(TERMINATED, IDLE, RESET);
  mActiveState = IDLE;
}

void Tutorial::run() {

  switch (mActiveState) {

    case ENTER_NAME: {
      view::Printer::directPrint("What is your name?");
      bool flush = true;
      name = input::readSentence(flush);
      view::Printer::clearScreen();
      view::Printer::directPrint("Hey there, " + name);
      mHandler.changePlayerName(World::activeCharacter, name);
      triggerTransition('b');
      break;
    }

    case INPUT_ANYKEY: {
      view::Printer::directPrint("Enter any key to start ..");

      std::string input = input::readSentence();

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
      view::Printer::directPrint(failOutput[attempts]);

      triggerTransition('d');
      break;
    }
  }
}

} // namespace controller
