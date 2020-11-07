//
// Created by riedel on 7/11/20.
//

#ifndef INC_7542_TALLER_PAGES_OSEXCEPTION_H
#define INC_7542_TALLER_PAGES_OSEXCEPTION_H

#include <string>

class OSexception: public std::exception {
 private:
    const int errnoCode;
    std::string error;
 public:
    explicit OSexception(const int& code);
    const char* what() const noexcept override;
};


#endif //INC_7542_TALLER_PAGES_OSEXCEPTION_H
