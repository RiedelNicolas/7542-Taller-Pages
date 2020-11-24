//
// Created by riedel on 7/11/20.
//

#include "OSexception.h"
#include <cstring>



OSexception::OSexception(const int &code): errnoCode(code) {
    this->error = strerror(this->errnoCode);
}

const char* OSexception::what() const noexcept {
    return error.c_str();
}


