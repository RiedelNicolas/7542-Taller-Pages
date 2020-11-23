//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONGET_H
#define INC_7542_TALLER_PAGES_PETITIONGET_H


#include "PetitionLogic.h"

class PetitionGet : public PetitionLogic {
 public:
    PetitionGet(ResourcesRepository &resources, PetitionParser &parser) :
        PetitionLogic(resources, parser ){}
    void execute() override;
};


#endif //INC_7542_TALLER_PAGES_PETITIONGET_H
