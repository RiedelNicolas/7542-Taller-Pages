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
 // Manages the incoming connections.
class RequestsManager: public Thread {
 private:
    Socket socket;
    std::atomic<bool> running;
    PrintMonitor printer;
    std::list<ClientHandler*> clients;
    ResourcesRepository resources;
    // Cleans the already finished clients.
    void cleanFinished();
    // Force all the clients to stop.
    void joinAll();
 public:
    // Constructor, receives a port to bind and a path from where read the
    // rootFile.
    RequestsManager(const std::string& port, const std::string& path);
    void run() override;
    // Checks if the thread has returned.
    bool done() override;
    // Force the Manager to stop receiving and kills all connections.
    void stop() override;
};


#endif  // SERVER_SRC_REQUESTSMANAGER_H_
