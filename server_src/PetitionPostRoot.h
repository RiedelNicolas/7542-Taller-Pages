//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONPOSTROOT_H
#define INC_7542_TALLER_PAGES_PETITIONPOSTROOT_H


#include "PetitionLogic.h"

class PetitionPostRoot : public PetitionLogic  {
private:
    std::stringstream petition;
public:
    void execute() override;
    std::string getAnswer() override;
    std::string getDisplay() override;
};


#endif //INC_7542_TALLER_PAGES_PETITIONPOSTROOT_H
