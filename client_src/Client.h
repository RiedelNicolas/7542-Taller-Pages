//
// Created by riedel on 12/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CLIENT_H
#define INC_7542_TALLER_PAGES_CLIENT_H


#include "../common_src/Socket.h"

class Client {
 private:
    Socket socket;
    std::string petition;
    void connect(char* host, char* port);
    void readPetition();
    void showPetition();
 public:
    void run(char* host, char* port);
};


#endif //INC_7542_TALLER_PAGES_CLIENT_H
