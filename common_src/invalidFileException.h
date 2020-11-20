//
// Created by riedel on 20/11/20.
//

#ifndef INC_7542_TALLER_PAGES_INVALIDFILEEXCEPTION_H
#define INC_7542_TALLER_PAGES_INVALIDFILEEXCEPTION_H


#include <exception>
#include <string>

class invalidFileException: public std::exception {
private:
    std::string error;
public:
    explicit  invalidFileException(std::string error);
    const char* what() const noexcept override;
};


#endif //INC_7542_TALLER_PAGES_INVALIDFILEEXCEPTION_H
