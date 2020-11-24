//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONPROCESSOR_H_
#define SERVER_SRC_PETITIONPROCESSOR_H_


#include <string>
#include "ResourcesRepository.h"
#include "PetitionLogic.h"
 // Process a petition. Contains an instance of PetitionLogic.
class PetitionProcessor {
 private:
    ResourcesRepository& resources;
    PetitionParser parser;
    PetitionLogic* petitionLogic;
 public:
    PetitionProcessor(ResourcesRepository& resources,
                      const std::string& petition);
    // gets the answer and display ready.
    void process();
    // gets the answer to the petitory (execute must have been run before).
    std::string getAnswer();
    // gets the message to shown on stdin.
    std::string getDisplay();
    ~PetitionProcessor();
    PetitionProcessor operator=(const PetitionProcessor& in) = delete;
    PetitionProcessor(const PetitionProcessor& in) = delete;
};


#endif  // SERVER_SRC_PETITIONPROCESSOR_H_
