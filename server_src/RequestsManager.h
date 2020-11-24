//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_REQUESTSMANAGER_H
#define INC_7542_TALLER_PAGES_REQUESTSMANAGER_H

#include <list>
#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include "ClientHandler.h"
#include "ResourcesRepository.h"

class RequestsManager: public Thread {
 private:
    Socket socket;
    std::atomic<bool> running;
    PrintMonitor printer;
    std::list<ClientHandler*> clients;
    ResourcesRepository resources;
    void cleanFinished();
    void joinAll();
 public:
    RequestsManager(const std::string& port, const std::string& path);
    void run() override;
    bool done() override;
    void stop() override;
};


#endif //INC_7542_TALLER_PAGES_REQUESTSMANAGER_H
