//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONPOST_H_
#define SERVER_SRC_PETITIONPOST_H_


#include "PetitionLogic.h"
// Derived from petition Logic.
// Implements the logic of answering a POST Petition.
class PetitionPost  : public PetitionLogic  {
 public:
    PetitionPost(ResourcesRepository &resources, PetitionParser &parser) :
    PetitionLogic(resources, parser ) {}
    void execute() override;
};


#endif  // SERVER_SRC_PETITIONPOST_H_
