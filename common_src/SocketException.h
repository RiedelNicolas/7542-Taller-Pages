//
// Created by riedel on 7/11/20.
//

#ifndef COMMON_SRC_SOCKETEXCEPTION_H_
#define COMMON_SRC_SOCKETEXCEPTION_H_

#include <exception>
#include <string>

class SocketException: public std::exception {
 private:
    std::string error;
 public:
    explicit  SocketException(const std::string& error);
     const char* what() const noexcept override;
};


#endif  // COMMON_SRC_SOCKETEXCEPTION_H_
