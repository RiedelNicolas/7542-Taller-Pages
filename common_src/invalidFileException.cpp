//
// Created by riedel on 20/11/20.
//

#include "invalidFileException.h"

const char *invalidFileException::what() const noexcept {
    return this->error.c_str();
}

invalidFileException::invalidFileException(std::string error): error(error) {

}
