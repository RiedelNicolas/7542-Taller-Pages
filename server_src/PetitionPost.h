//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONPOST_H
#define INC_7542_TALLER_PAGES_PETITIONPOST_H


#include "PetitionLogic.h"

class PetitionPost  : public PetitionLogic  {
private:
    std::stringstream petition;
public:
    void execute() override;
};


#endif //INC_7542_TALLER_PAGES_PETITIONPOST_H
