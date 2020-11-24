//
// Created by riedel on 22/11/20.
//

#ifndef SERVER_SRC_PETITIONGET_H_
#define SERVER_SRC_PETITIONGET_H_


#include "PetitionLogic.h"
  // Derived from petition Logic.
  // Implements the logic of answering a GET Petition.
class PetitionGet : public PetitionLogic {
 public:
    // Calls the base constructor.
    PetitionGet(ResourcesRepository &resources, PetitionParser &parser) :
                                PetitionLogic(resources, parser ) {}
    void execute() override;
};


#endif  // SERVER_SRC_PETITIONGET_H_
