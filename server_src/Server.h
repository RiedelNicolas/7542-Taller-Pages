//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_SERVER_H
#define INC_7542_TALLER_PAGES_SERVER_H


#include <string>
#include <sstream>

class Server {
 private:
    std::string port;
    std::string path;
    void waitCharacter (const char waited);
 public:
    explicit Server(const std::string& port, const std::string& rootPath);

    void operator()();
};

#endif //INC_7542_TALLER_PAGES_SERVER_H
