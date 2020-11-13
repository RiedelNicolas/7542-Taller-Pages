//
// Created by riedel on 8/11/20.
//

#include <fstream>
#include "Server.h"
#include "Controller.h"
#include "RequestsManager.h"

void Server::operator()() {
    Controller cont('q');
    RequestsManager manager(port, path);
    cont.start();
    manager.start();
    while(cont.done() == false);
    cont.join();
    manager.stop();
    manager.join();
}



Server::Server(const std::string& port, const std::string& path): port(port),
                                                                  path(path){
}
