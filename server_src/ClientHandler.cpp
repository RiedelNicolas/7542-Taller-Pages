//
// Created by riedel on 8/11/20.
//

#include "ClientHandler.h"

void ClientHandler::run() {

}

void ClientHandler::stop() {
    this->done = true;
}

ClientHandler::ClientHandler() {
    this->done = false;
}
