//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONLOGIC_H_
#define SERVER_SRC_PETITIONLOGIC_H_


#include <sstream>
#include <string>
#include "PetitionParser.h"
#include "ResourcesRepository.h"
  // Virtual class, represents the logic behind answering an http petition.
class PetitionLogic {
 protected:
    ResourcesRepository& resources;
    PetitionParser& parser;
    std::string answer;
    PetitionLogic(ResourcesRepository &resources, PetitionParser &parser);
 public:
    // get the first line of the petitory.
    std::string getFirstLine();
    virtual void execute() = 0;
    // gets the answer to the petitory (execute must have been run before).
    std::string getAnswer();
    virtual ~PetitionLogic() {}
};

#endif  // SERVER_SRC_PETITIONLOGIC_H_
