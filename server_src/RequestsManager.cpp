//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include "RequestsManager.h"

RequestsManager::RequestsManager(std::string port) {
    this->peer.bindToPort(port);
    this->peer.listenIncoming();
}

void RequestsManager::run() {

    while( !(this->done) ) {
        try {
            int fd = this->peer.acceptOne();
            this->clients.push_back( new ClientHandler(fd) );
            this->clean();
        }catch (std::exception& e) {
            std::cerr << e.what() << std::endl;

        } catch (...) {
            std::cerr << "Unknown error"<< std::endl;
            this->done = true;
        }
    }

}

void RequestsManager::clean() {
    for (auto&i : clients ){
        if( i->done() ){
            i->join();
        }
    }
}

void RequestsManager::joinAll() {
    for (auto&i : clients ){
        i.join();
    }
}
