//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONINVALID_H_
#define SERVER_SRC_PETITIONINVALID_H_


#include "PetitionLogic.h"

class PetitionInvalid  : public PetitionLogic  {
 public:
    PetitionInvalid(ResourcesRepository &resources, PetitionParser &parser) :
                                    PetitionLogic(resources, parser) {}
    void execute() override;
};


#endif  // SERVER_SRC_PETITIONINVALID_H_
