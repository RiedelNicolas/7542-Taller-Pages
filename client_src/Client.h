//
// Created by riedel on 12/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CLIENT_H
#define INC_7542_TALLER_PAGES_CLIENT_H


#include "../common_src/Socket.h"
#include <sstream>

class Client {
 private:
    Socket socket;
    std::ostringstream petition;
    std::string result;
    void connect(char* host, char* port);
    void readPetition();
    void showResult();
    void sendPetition();
    void receiveResult();

 public:
    void run(char* host, char* port);
};


#endif //INC_7542_TALLER_PAGES_CLIENT_H
