//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

namespace view {

Printer::Printer(const Verbose verbose) : verbose(verbose){
}

void Printer::setVerboseLevel(const Verbose verbose) {
  Printer::verbose = verbose;
}

}