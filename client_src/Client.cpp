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
    char ch;
    while(std::cin >> ch){
        petition.push_back(ch);
    }
}

void Client::showResult() {
    std::cout << result;
}

void Client::sendPetition() {
    socket.send(result);
}

void Client::receiveResult() {
    socket.receive(result);
}


