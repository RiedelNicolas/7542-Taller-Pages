//
// Created by riedel on 12/11/20.
//

#ifndef CLIENT_SRC_CLIENT_H_
#define CLIENT_SRC_CLIENT_H_

#include <sstream>
#include <string>
#include "../common_src/Socket.h"

  // Client.
class Client {
 private:
    Socket socket;
    std::ostringstream petition;
    std::string result;
    void connect(char* host, char* port);
    void readPetition();
    void sendPetition();
    void receiveResult();
    void showResult() const;

 public:
    // wraps all the logic. Sends a Http petition to the server, then shows
    // the received answer on the screen.
    void run(char* host, char* port);
};


#endif  // CLIENT_SRC_CLIENT_H_
