//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONLOGIC_H
#define INC_7542_TALLER_PAGES_PETITIONLOGIC_H


#include <sstream>
#include "PetitionParser.h"
#include "ResourcesRepository.h"

class PetitionLogic {
 private:
    PetitionParser parser;
    ResourcesRepository& resources;
    std::string answer;
 public:
    PetitionLogic(const std::string &petition, ResourcesRepository &resources);
    std::string getFirstLine();
    virtual void execute() = 0;
    virtual std::string getAnswer() = 0;
    virtual ~PetitionLogic() = 0;
};

#endif //INC_7542_TALLER_PAGES_PETITIONLOGIC_H
