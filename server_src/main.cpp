//
// Created by riedel on 7/11/20.
//

#include "../common_src/Socket.h"
#include "Controller.h"
#include "ClientHandler.h"

int main(){
    Socket peer;
    Socket socket;
    peer.bindToPort("8085");
    peer.listenIncoming();
    socket = peer.acceptOne();
    ClientHandler handler(socket);
    handler.run();
    return 0;
}
