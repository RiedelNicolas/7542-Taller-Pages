//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include <fstream>
#include "RequestsManager.h"
#include "PrintMonitor.h"

RequestsManager::RequestsManager(std::string port, std::string path) {
    this->socket.bindToPort(port);
    this->socket.listenIncoming();
    this->running = true;
    std::ifstream inFile;
    inFile.open(path);
    stream << inFile.rdbuf();
}

void RequestsManager::run() {
    PrintMonitor printer;
    while( this->running ) {
        int peer = this->socket.acceptOne();
        this->clean();
        if (peer != -1) {
            this->clients.push_back( new ClientHandler(peer, printer, stream.str() ) );
            clients.back()->start();
        } else {
        this->running = false;
        }
    }
    this->joinAll();
}


void RequestsManager::joinAll() {

    for(size_t i = 0; i < clients.size(); i++ ){
        if(clients[i] == nullptr) continue;
        clients[i]->join();
        delete clients[i];
        clients[i] = nullptr;
    }
}

void RequestsManager::clean() {
    for(size_t i = 0; i < clients.size(); i++ ){
        if(clients[i] == nullptr) continue;

        if( clients[i]->done() ){
            clients[i]->join();
            delete clients[i];
            clients[i] = nullptr;
        }
    }
}

bool RequestsManager::done() {
    return !running;
}

void RequestsManager::stop() {
    socket.close();
    this->running = false;
}

