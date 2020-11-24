//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONINVALID_H_
#define SERVER_SRC_PETITIONINVALID_H_


#include "PetitionLogic.h"
  // Derived from petition Logic.
  // Implements the logic of answering an invalid Petition.
class PetitionInvalid  : public PetitionLogic  {
 public:
    // calls the base constructor.
    PetitionInvalid(ResourcesRepository &resources, PetitionParser &parser) :
                                    PetitionLogic(resources, parser) {}
    void execute() override;
};


#endif  // SERVER_SRC_PETITIONINVALID_H_
