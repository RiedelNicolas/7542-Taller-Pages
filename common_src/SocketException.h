//
// Created by riedel on 7/11/20.
//

#ifndef INC_7542_TALLER_PAGES_SOCKETEXCEPTION_H
#define INC_7542_TALLER_PAGES_SOCKETEXCEPTION_H

#include <exception>
#include <string>

class SocketException: public std::exception {
 private:
    std::string error;
 public:
    explicit  SocketException(std::string error);

};


#endif //INC_7542_TALLER_PAGES_SOCKETEXCEPTION_H
