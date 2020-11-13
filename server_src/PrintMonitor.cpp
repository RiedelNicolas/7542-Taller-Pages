//
// Created by riedel on 13/11/20.
//

#include <iostream>
#include "PrintMonitor.h"
#include "../common_src/Bloquear.h"

void PrintMonitor::print(std::string in) {
    Bloquear b(this->m);
    std::cout << in << std::endl;
}
