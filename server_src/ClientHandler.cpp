//
// Created by riedel on 8/11/20.
//

#include "ClientHandler.h"

void ClientHandler::run() {
    char mensaje[50];
    ssize_t recibido = this->socket.receive(mensaje,50);
    mensaje[recibido] = (char) 0;
}

void ClientHandler::stop() {
    this->done = true;
}

ClientHandler::ClientHandler(Socket socket) {
    this->done = false;
    this->socket = socket;
}
