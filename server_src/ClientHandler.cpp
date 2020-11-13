//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include "ClientHandler.h"
#include "PetitionParser.h"

void ClientHandler::run() {
    this->receivePetition();
    PetitionParser parser(petition);
    printer.print( parser.getFirstLine() );
    this->process();
    this->sendResult();
    socket.endWriting();
    this->stop();
}

void ClientHandler::stop() {
    this->running = false;
    socket.close();
}

ClientHandler::ClientHandler(const int fd, PrintMonitor &printer)
                                        : socket(fd), printer(printer) {
    this->running = true;
}

void ClientHandler::receivePetition() {
    socket.receive(petition);
}

void ClientHandler::process() {
    result = petition;
}

void ClientHandler::sendResult() {
    socket.send(result.c_str(), result.length());
}

bool ClientHandler::done() {
    return !running;
}
