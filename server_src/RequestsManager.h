//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_REQUESTSMANAGER_H
#define INC_7542_TALLER_PAGES_REQUESTSMANAGER_H

#include <vector>
#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include "ClientHandler.h"

class RequestsManager: public Thread{
 private:
    Socket peer;
    bool done;
    std::vector<Threads*> clients;
    void clean();
    void joinAll();
 public:
    explicit RequestsManager(std::string port);
    void run() override;
};


#endif //INC_7542_TALLER_PAGES_REQUESTSMANAGER_H
