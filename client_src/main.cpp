//
// Created by riedel on 7/11/20.
//

#include "../common_src/Socket.h"

int main(){
    Socket socket;
    socket.connectTo("localhost","8080");
    std::string mensaje("Hola server");
    socket.send( mensaje.c_str(),mensaje.length() );
}