//
// Created by riedel on 12/11/20.
//

#include <iostream>
#include "Client.h"
#define BUFFER_LEN 64

void Client::run(char* host, char* port) {
    this->connect(host, port);
}

void Client::connect(char *host, char *port) {
    socket.connectTo(host, port);
    this->readPetition();
    this->sendPetition();
    this->receiveResult();
    this->showResult();
}

void Client::readPetition() {
    int c;
    while (std::cin >> c){
        this->petition.push_back(c);
    }
}

void Client::showResult() {
    std::cout << this->result;
}

void Client::sendPetition() {
    socket.send(petition.c_str(), petition.length() );
}

void Client::receiveResult() {
    char buffer [BUFFER_LEN];
    ssize_t read;
    do {
        read = socket.receive(buffer, BUFFER_LEN);
        result.append(buffer, read);
    } while (read == BUFFER_LEN);
}




