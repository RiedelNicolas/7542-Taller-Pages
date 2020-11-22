//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include "ClientHandler.h"
#include "PetitionParser.h"

void ClientHandler::run() {

    PetitionParser parser(this->receivePetition());
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

std::string ClientHandler::receivePetition() {
    std::string petition;
    socket.receive(petition);
    return petition;
}

void ClientHandler::process() {
    result = "esta deberia ser la respuesta del servidor";
}

void ClientHandler::sendResult() {
    socket.send(result.c_str(), result.length());
}

bool ClientHandler::done() {
    return !running;
}

ClientHandler::ClientHandler(const int fd, PrintMonitor &printer,
                             ResourcesRepository &resources): printer(printer),
                             resources(resources){
    this->running = true;
}
