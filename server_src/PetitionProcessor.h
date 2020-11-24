//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONPROCESSOR_H_
#define SERVER_SRC_PETITIONPROCESSOR_H_


#include <string>
#include "ResourcesRepository.h"
#include "PetitionLogic.h"

class PetitionProcessor {
 private:
    ResourcesRepository& resources;
    PetitionParser parser;
    PetitionLogic* petitionLogic;
 public:
    PetitionProcessor(ResourcesRepository& resources,
                      const std::string& petition);
    void process();
    std::string getAnswer();
    std::string getDisplay();
    ~PetitionProcessor();
};


#endif  // SERVER_SRC_PETITIONPROCESSOR_H_
