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

  // Client handler, when a new client connects a new instance is created.
  // Handles all the interactions with the different clients.
class ClientHandler : public Thread {
 private:
    Socket socket;
    std::atomic<bool> running;
    PrintMonitor& printer;
    ResourcesRepository& resources;
    // Receives petition from the client.
    std::string receivePetition();
    // Sends result of the petition to the client.
    void sendResult(const std::string& result);
 public:
    // Constructor, receives a socket by movement, reference to a printMonitor,
    // and a resource repository successfully created.
    ClientHandler(Socket&& peer, PrintMonitor& printer,
                  ResourcesRepository& resources);
    // Logic.
    void run() override;
    // Force the Thread to stop.
    void stop() override;
    // Check if the Thread has already returned.
    bool done() override;
};


#endif  // SERVER_SRC_CLIENTHANDLER_H_
