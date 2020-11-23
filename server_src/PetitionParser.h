//
// Created by riedel on 13/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PETITIONPARSER_H
#define INC_7542_TALLER_PAGES_PETITIONPARSER_H


#include <sstream>

class PetitionParser {
 private:
    std::istringstream petition;

 public:
    explicit PetitionParser(std::string in);
    std::string getMethod();
    std::string getFirstLine();
    std::string getResource();
    std::string getBody();
};

#endif //INC_7542_TALLER_PAGES_PETITIONPARSER_H
