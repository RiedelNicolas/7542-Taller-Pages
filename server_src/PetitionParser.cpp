//
// Created by riedel on 13/11/20.
//

#include "PetitionParser.h"

PetitionParser::PetitionParser(std::string in): petition(in) {

}

std::string PetitionParser::getFirstLine() {
    std::string aux;
    std::getline(petition,aux);
    return aux;
}
