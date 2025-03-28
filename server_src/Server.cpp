//
// Created by riedel on 8/11/20.
//

#include "Server.h"
#include "RequestsManager.h"

void Server::operator()() {
    RequestsManager manager(port, path);
    manager.start();
    waitCharacter('q');  // blocking
    manager.stop();
    manager.join();
}

Server::Server(const std::string& port, const std::string& rootPath)
                                                        : port(port),
                                                        path(rootPath) {
}
  // Blocking function, waits for a specified character.
void Server::waitCharacter(const char waited) {
    char c;
    do {
        c = getchar();
    } while (c != waited);
}



