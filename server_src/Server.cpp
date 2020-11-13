//
// Created by riedel on 8/11/20.
//

#include "Server.h"
#include "Controller.h"

void Server::operator()() {
    Controller cont('q');

}

Server::Server(const std::string& port): port(port) {

}
