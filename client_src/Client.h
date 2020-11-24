//
// Created by riedel on 12/11/20.
//

#ifndef CLIENT_SRC_CLIENT_H_
#define CLIENT_SRC_CLIENT_H_

#include <sstream>
#include <string>
#include "../common_src/Socket.h"


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


#endif  // CLIENT_SRC_CLIENT_H_
