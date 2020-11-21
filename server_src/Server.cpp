//
// Created by riedel on 8/11/20.
//

#include <fstream>
#include "Server.h"
#include "RequestsManager.h"

void Server::operator()() {
    RequestsManager manager(port, path);
    manager.start();
    while(cont.done() == false);
    cont.join();
    manager.stop();
    manager.join();
}



Server::Server(const std::string& port, const std::string& path): port(port),
                                                                  path(path){
}

void Server::serverWaitCharacter(const char waited) {

}


