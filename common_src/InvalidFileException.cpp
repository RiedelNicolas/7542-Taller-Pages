//
// Created by riedel on 20/11/20.
//

#include "InvalidFileException.h"

const char *InvalidFileException::what() const noexcept {
    return this->error.c_str();
}

InvalidFileException::InvalidFileException(const std::string& error)
                                                    : error(error) {
}
