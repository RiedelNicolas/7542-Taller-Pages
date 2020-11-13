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
    bool running;
    std::string petition;
    std::string result;
    void receivePetition();
    void process();
    void sendResult();
 public:

    ClientHandler(const int fd);
    void run() override;
    void stop();
    bool done();
};


#endif //INC_7542_TALLER_PAGES_CLIENTHANDLER_H
