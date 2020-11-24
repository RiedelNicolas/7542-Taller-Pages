//
// Created by riedel on 8/11/20.
//

#ifndef SERVER_SRC_SERVER_H_
#define SERVER_SRC_SERVER_H_


#include <string>
#include <sstream>

class Server {
 private:
    std::string port;
    std::string path;
    void waitCharacter(const char waited);
 public:
    explicit Server(const std::string& port, const std::string& rootPath);
    // runs the logic of the server.
    void operator()();
};

#endif  // SERVER_SRC_SERVER_H_
