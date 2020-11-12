//
// Created by riedel on 7/11/20.
//

#include "../common_src/Socket.h"
#include "Controller.h"
int main(){

    Controller controller('q');
    controller.start();
    printf("aca anda suelta xd");
    controller.join();
    printf("desbloqueo");

   /* Socket socket;
    socket.bindToPort("8080");
    socket.listenIncoming();
    Socket peer = socket.acceptOne();
    Socket peer2 = socket.acceptOne();
    char mensaje [50];
    ssize_t recibido = peer.receive(mensaje, 50);
    mensaje[recibido] = '\0';
    recibido = peer2.receive(mensaje, 50);
    mensaje[recibido] = '\0';
    */
    }