//
// Created by riedel on 8/11/20.
//

#include "ClientHandler.h"

void ClientHandler::run() {
    std::string petition;

}

void ClientHandler::stop() {
    this->done = true;
}

ClientHandler::ClientHandler(Socket socket) {
    this->done = false;
    this->socket = socket;
}
