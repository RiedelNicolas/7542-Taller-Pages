//
// Created by riedel on 8/11/20.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "RequestsManager.h"
#include "PrintMonitor.h"

RequestsManager::RequestsManager(const std::string& port, const std::string& path)
                                                                :resources(path) {
    this->socket.bindToPort(port);
    this->socket.listenIncoming();
    this->running = true;
}

void RequestsManager::run() {
    while( this->running ) {
        Socket peer = this->socket.acceptOne();
        this->cleanFinished();
        if ( peer.valid() ) {
            this->clients.push_back( new ClientHandler
                (std::move(peer),printer, resources ) );
            clients.back()->start();
        } else {
        this->running = false;
        }
    }
    this->joinAll();
}

bool clientReaper(ClientHandler* clientHandler){
    if(clientHandler->done()){
        clientHandler->join();
        delete clientHandler;
        return true;
    }
    return false;
}

void RequestsManager::cleanFinished() {
    this->clients.erase(std::remove_if(clients.begin(),
                                       clients.end(),clientReaper ),
                                                clients.end());
}


void RequestsManager::joinAll() {

    for (auto i :  clients) {
        i->join();
        delete i;
    }
}

bool RequestsManager::done() {
    return !running;
}

void RequestsManager::stop() {
    socket.close();
    this->running = false;
}


