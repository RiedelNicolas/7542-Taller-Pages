//
// Created by riedel on 20/11/20.
//

#ifndef COMMON_SRC_INVALIDFILEEXCEPTION_H_
#define COMMON_SRC_INVALIDFILEEXCEPTION_H_


#include <exception>
#include <string>
  // The file could not be found.
class InvalidFileException: public std::exception {
 private:
    std::string error;
 public:
    explicit  InvalidFileException(const std::string& error);
    const char* what() const noexcept override;
};


#endif  // COMMON_SRC_INVALIDFILEEXCEPTION_H_
