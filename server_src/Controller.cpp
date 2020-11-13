//
// Created by riedel on 9/11/20.
//

#include "Controller.h"
#include <iostream>
#include <cstdio>

Controller::Controller(const char end): end(end) {
 this->running = false;
}

bool Controller::done() {
    return !(this->running);
}

void Controller::run() {
    this->running = true;
    char c;
    do {
        c = getchar();
    } while (c != this->end);

    this->running = false;
}

void Controller::stop() {
    this->running = false;
}
