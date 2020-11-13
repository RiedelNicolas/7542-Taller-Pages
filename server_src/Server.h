//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_SERVER_H
#define INC_7542_TALLER_PAGES_SERVER_H


#include <string>

class Server {
    std::string port;
 public:
    explicit Server(const std::string& port);
    void operator()();
};

#endif //INC_7542_TALLER_PAGES_SERVER_H
