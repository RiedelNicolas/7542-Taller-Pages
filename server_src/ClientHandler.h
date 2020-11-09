//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CLIENTHANDLER_H
#define INC_7542_TALLER_PAGES_CLIENTHANDLER_H


#include "../common_src/Thread.h"
#include "../common_src/Socket.h"

class ClientHandler : public Thread {
 private:
    Socket socket;
    bool done;
 public:
    ClientHandler(Socket socket);
    void run() override;
    void stop();
};


#endif //INC_7542_TALLER_PAGES_CLIENTHANDLER_H
