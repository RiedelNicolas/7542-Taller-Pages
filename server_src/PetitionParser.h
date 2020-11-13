//
// Created by riedel on 13/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONPARSER_H
#define INC_7542_TALLER_PAGES_PETITIONPARSER_H


#include <sstream>

class PetitionParser {
 private:
    std::stringstream petition;

 public:
    PetitionParser(std::string in);
};


#endif //INC_7542_TALLER_PAGES_PETITIONPARSER_H
