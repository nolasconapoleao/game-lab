//
// Created by nolasco on 27/06/20.
//

#pragma once

enum Transitions : char {
  START = 's',
  TERMINATE = 'x',
  CANCEL = 'b',
  RESET = 'r',
  PREVIOUS = 'p',
  NEXT = 'n',

  CORRECT = '+',
  INCORRECT = '-',
  FORGIVEN = 'f',
};
