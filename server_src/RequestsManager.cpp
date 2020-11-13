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
            this->clients.emplace_back(  ClientHandler(fd)  );

        }catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            this->done = true;
        } catch (...) {
            std::cerr << "Unknown error"<< std::endl;
        }
    }
}
