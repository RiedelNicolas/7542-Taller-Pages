//
// Created by riedel on 7/11/20.
//

#include "../common_src/Socket.h"
#include "Controller.h"
#include "ClientHandler.h"

int main(){
    Socket peer;
    int fd;
    peer.bindToPort("8090");
    peer.listenIncoming();
    fd = peer.acceptOne();
    ClientHandler handler(fd);
    handler.run();
    return 0;
}
