//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include <string>
#include <utility>
#include "ClientHandler.h"

void ClientHandler::run() {
    PetitionProcessor petProcessor(resources, this->receivePetition());
    petProcessor.process();
    printer.print(petProcessor.getDisplay());
    this->sendResult(petProcessor.getAnswer());
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

void ClientHandler::sendResult(const std::string& result) {
    socket.send(result.c_str(), result.length());
}

bool ClientHandler::done() {
    return !running;
}

ClientHandler::ClientHandler(Socket&& peer, PrintMonitor &printer,
                             ResourcesRepository &resources):
                             socket(std::move(peer)),
                             printer(printer),
                             resources(resources) {
    this->running = true;
}

