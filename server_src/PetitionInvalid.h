//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONINVALID_H
#define INC_7542_TALLER_PAGES_PETITIONINVALID_H


#include "PetitionLogic.h"

class PetitionInvalid  : public PetitionLogic  {
 public:
    PetitionInvalid(ResourcesRepository &resources, PetitionParser &parser) :
    PetitionLogic(resources, parser ){}
    void execute() override;
};


#endif //INC_7542_TALLER_PAGES_PETITIONINVALID_H
