//
// Created by riedel on 8/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CLIENTHANDLER_H
#define INC_7542_TALLER_PAGES_CLIENTHANDLER_H


#include <sstream>
#include <atomic>
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


#endif //INC_7542_TALLER_PAGES_CLIENTHANDLER_H
