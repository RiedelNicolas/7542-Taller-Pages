//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_SERVER_H
#define INC_7542_TALLER_PAGES_SERVER_H


#include <string>
#include <sstream>

class Server {
    std::string port;
    std::stringstream stream;
 public:
    explicit Server(const std::string& port, const std::string& path);

    Server(const std::stringstream &stream);

    void operator()();
};

#endif //INC_7542_TALLER_PAGES_SERVER_H
