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

std::string PetitionParser::getMethod() {
    std::string line = this->getFirstLine();
     return line.substr(0,line.find_first_of('/') );
}

std::string PetitionParser::getResource() {
    return std::__cxx11::string();
}

std::string PetitionParser::getBody() {
    return std::__cxx11::string();
}
