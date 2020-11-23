//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONPROCESSOR_H
#define INC_7542_TALLER_PAGES_PETITIONPROCESSOR_H


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


#endif //INC_7542_TALLER_PAGES_PETITIONPROCESSOR_H
