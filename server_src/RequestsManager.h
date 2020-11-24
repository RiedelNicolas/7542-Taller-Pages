//
// Created by riedel on 8/11/20.
//

#ifndef SERVER_SRC_REQUESTSMANAGER_H_
#define SERVER_SRC_REQUESTSMANAGER_H_

#include <list>
#include <string>
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


#endif  // SERVER_SRC_REQUESTSMANAGER_H_
