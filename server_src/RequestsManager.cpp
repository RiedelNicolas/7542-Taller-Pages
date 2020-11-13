//
// Created by riedel on 8/11/20.
//

#include "RequestsManager.h"

RequestsManager::RequestsManager(std::string port) {
    this->peer.bindToPort(port);
    this->peer.listenIncoming();
}

void RequestsManager::run() {

    while( !(this->done) ) {
        try {
            Socket temp = this->peer.acceptOne();
            this->clients.push_back(this->peer.acceptOne() );

        }catch (std::exception& e) {
            this->done = true;
        }
    }
}
