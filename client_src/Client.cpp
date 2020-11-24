//
// Created by riedel on 12/11/20.
//

#include <iostream>
#include "Client.h"

void Client::run(char* host, char* port) {
    this->connect(host, port);
}
  // Connect with the specified host and port.
void Client::connect(char *host, char *port) {
    socket.connectTo(host, port);
    this->readPetition();
    this->sendPetition();
    socket.endWriting();
    this->receiveResult();
    this->showResult();
}
  // Reads HTTP petition from STDIN.
void Client::readPetition() {
    petition << std::cin.rdbuf();
}
  // Shows answer on STDOUT.
void Client::showResult() const {
    std::cout << result;
}
  // Sends petition to the previously connect server.
void Client::sendPetition() {
    socket.send(petition.str());
}
  // Receives server's petition answer.
void Client::receiveResult() {
    socket.receive(result);
}


