//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONLOGIC_H
#define INC_7542_TALLER_PAGES_PETITIONLOGIC_H


#include <sstream>
#include "PetitionParser.h"
#include "ResourcesRepository.h"

class PetitionLogic {
 protected:
    ResourcesRepository& resources;
    PetitionParser& parser;
    std::string answer;
    PetitionLogic(ResourcesRepository &resources, PetitionParser &parser );
 public:
    std::string getFirstLine();
    virtual void execute() = 0;
    std::string getAnswer();
    virtual ~PetitionLogic() {};
};

#endif //INC_7542_TALLER_PAGES_PETITIONLOGIC_H
