//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include "datatypes/logger/PrintConstants.h"
#include "platform/platformconfig.h"

namespace view {

void Printer::clearScreen() {
#ifdef COMPILE_FOR_NON_UNIX
  std::system("cls");
#else
  std::system("clear");
#endif
}

} // namespace view
