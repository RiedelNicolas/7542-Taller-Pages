//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include "RequestsManager.h"

RequestsManager::RequestsManager(std::string port) {
    this->peer.bindToPort(port);
    this->peer.listenIncoming();
    this->running = true;
}

void RequestsManager::run() {

    while( this->running ) {
        try {
            int fd = this->peer.acceptOne();
            this->clean();
            this->clients.push_back( new ClientHandler(fd) );
            this->clients.back()->start();
        }catch (std::exception& e) {
            std::cerr << e.what() << std::endl;

        } catch (...) {
            std::cerr << "Unknown error"<< std::endl;
        }
    }
    this->running = false;
    this->joinAll();
}





void RequestsManager::joinAll() {

    for(size_t i = 0; i < clients.size(); i++ ){
        clients[i]->join();
        delete clients[i];
    }
}

void RequestsManager::clean() {
    for(size_t i = 0; i < clients.size(); i++ ){
        if( clients[i]->done() )
        clients[i]->join();
    }
}

bool RequestsManager::done() {
    return !running;
}

void RequestsManager::stop() {
    peer.close();
    this->running = false;
}

