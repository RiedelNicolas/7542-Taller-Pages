//
// Created by riedel on 8/11/20.
//

#ifndef SERVER_SRC_CLIENTHANDLER_H_
#define SERVER_SRC_CLIENTHANDLER_H_


#include <sstream>
#include <atomic>
#include <string>
#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include "PrintMonitor.h"
#include "ResourcesRepository.h"
#include "PetitionProcessor.h"

class ClientHandler : public Thread {
 private:
    Socket socket;
    std::atomic<bool> running;
    PrintMonitor& printer;
    ResourcesRepository& resources;
    std::string receivePetition();
    void sendResult(const std::string& result);
 public:
    ClientHandler(Socket&& peer, PrintMonitor& printer,
                  ResourcesRepository& resources);
    void run() override;
    void stop() override;
    bool done() override;
};


#endif  // SERVER_SRC_CLIENTHANDLER_H_
