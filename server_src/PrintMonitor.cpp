//
// Created by riedel on 13/11/20.
//

#include <iostream>
#include <string>
#include "PrintMonitor.h"
#include "../common_src/Lock.h"

void PrintMonitor::print(const std::string& in) {
    Lock b(this->m);
    std::cout << in << std::endl;
}
