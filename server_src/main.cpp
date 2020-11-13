//
// Created by riedel on 7/11/20.
//

#include "../common_src/Socket.h"
#include "Controller.h"
#include "ClientHandler.h"

int main(){
    Socket peer;
    Socket socket;
    peer.bindToPort("8088");
    peer.listenIncoming();
    ClientHandler handler( std::move( peer.acceptOne() ) );
    handler.run();
    return 0;
}
