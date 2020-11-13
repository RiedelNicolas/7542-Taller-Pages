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
    this->done = true;
}

ClientHandler::ClientHandler(Socket socket) {
    this->done = false;
    this->socket = socket;
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

bool ClientHandler::isDone() {
    return done;
}
