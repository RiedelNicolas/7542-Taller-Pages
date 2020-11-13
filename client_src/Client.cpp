//
// Created by riedel on 12/11/20.
//

#include <iostream>
#include "Client.h"

void Client::run(char* host, char* port) {
    this->connect(host, port);
}

void Client::connect(char *host, char *port) {
    socket.connectTo(host, port);
    this->readPetition();
    this->sendPetition();
    socket.endWriting();
    this->receiveResult();
    this->showResult();
}

void Client::readPetition() {
    petition << std::cin.rdbuf();
}

void Client::showResult() {
    std::cout << result;
}

void Client::sendPetition() {
    socket.send( petition.str() );
}

void Client::receiveResult() {
    socket.receive(result);
}


