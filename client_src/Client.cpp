//
// Created by riedel on 12/11/20.
//

#include "Client.h"

void Client::run(char* host, char* port) {
    this->connect(host, port);
}

void Client::connect(char *host, char *port) {
    socket.connectTo(host, port);
    this->readPetition();
    socket.send(petition.c_str(), petition.length() );

}

void Client::readPetition() {
    return ;
}

void Client::showPetition() {
    return;
}


