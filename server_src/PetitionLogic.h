//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONLOGIC_H_
#define SERVER_SRC_PETITIONLOGIC_H_


#include <sstream>
#include <string>
#include "PetitionParser.h"
#include "ResourcesRepository.h"

class PetitionLogic {
 protected:
    ResourcesRepository& resources;
    PetitionParser& parser;
    std::string answer;
    PetitionLogic(ResourcesRepository &resources, PetitionParser &parser);
 public:
    std::string getFirstLine();
    virtual void execute() = 0;
    std::string getAnswer();
    virtual ~PetitionLogic() {}
};

#endif  // SERVER_SRC_PETITIONLOGIC_H_
