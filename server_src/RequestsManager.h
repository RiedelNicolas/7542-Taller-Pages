//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_REQUESTSMANAGER_H
#define INC_7542_TALLER_PAGES_REQUESTSMANAGER_H

#include <vector>
#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include "ClientHandler.h"

class RequestsManager: public Thread {
 private:
    Socket socket;
    bool running;
    PrintMonitor printer;
    std::vector<Thread*> clients;
    ResourcesMonitor resources;
    void clean();
    void joinAll();
 public:
    RequestsManager(std::string port, std::string path);
    void run() override;
    bool done() override;
    void stop() override;
};


#endif //INC_7542_TALLER_PAGES_REQUESTSMANAGER_H
