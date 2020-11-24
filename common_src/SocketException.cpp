//
// Created by riedel on 7/11/20.
//

#include "SocketException.h"

SocketException::SocketException(std::string error): error(error) {
}

const char* SocketException::what() const noexcept {
    return this->error.c_str();
}





