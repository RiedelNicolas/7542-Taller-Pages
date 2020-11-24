//
// Created by riedel on 7/11/20.
//

#ifndef COMMON_SRC_OSEXCEPTION_H_
#define COMMON_SRC_OSEXCEPTION_H_

#include <string>

class OSexception: public std::exception {
 private:
    const int errnoCode;
    std::string error;
 public:
    explicit OSexception(const int& code);
    const char* what() const noexcept override;
};


#endif  // COMMON_SRC_OSEXCEPTION_H_
