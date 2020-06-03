#include <controller/Controller.h>
#include <iostream>

int main() {
  controller::Controller ctrl;

  std::cout << "What is your name?\n";
  const auto name = ctrl.readSentence();
  std::cout << "Hey " << name << "\n";

  std::cout << "Enter a value between 1 and 5, or a base option (x,m):\n";
  const auto alphaNum = ctrl.readAlphaNumeric(5);
  std::cout << "Read " << alphaNum << "\n";

  return 0;
}
