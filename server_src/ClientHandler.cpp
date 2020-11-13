//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include "ClientHandler.h"

void ClientHandler::run() {
    this->receivePetition();
    std::cout << petition;
    this->process();
    this->sendResult();
    socket.endWriting();
    this->stop();
}

void ClientHandler::stop() {
    this->running = false;
}

ClientHandler::ClientHandler(const int fd): socket(fd) {
    this->running = true;
}

void ClientHandler::receivePetition() {
    socket.receive(this->petition);
}

void ClientHandler::process() {
    result = "Hola susana";
}

void ClientHandler::sendResult() {
    socket.send(result.c_str(), result.length());
}

bool ClientHandler::done() {
    return !running;
}
