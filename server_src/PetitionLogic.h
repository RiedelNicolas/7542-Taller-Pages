//
// Created by riedel on 22/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONLOGIC_H
#define INC_7542_TALLER_PAGES_PETITIONLOGIC_H


#include <sstream>

class PetitionLogic {
 private:
    std::stringstream petition;
 public:
    PetitionLogic(const std::string& petition);
    std::string getFirstLine();
    virtual void execute() = 0;
    virtual std::string getAnswer() = 0;
    virtual std::string getDisplay() = 0;
};


#endif //INC_7542_TALLER_PAGES_PETITIONLOGIC_H
