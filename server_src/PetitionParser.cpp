//
// Created by riedel on 13/11/20.
//

#include <string>
#include "PetitionParser.h"

PetitionParser::PetitionParser(std::string in): petition(in) {
}

std::string PetitionParser::getFirstLine() {
    petition.clear();
    petition.seekg(0);
    std::string aux;
    std::getline(petition, aux);
    return aux;
}

std::string PetitionParser::getMethod() {
    std::string line = this->getFirstLine();
     return line.substr(0, line.find_first_of('/') -1 );
}

std::string PetitionParser::getResource() {
    std::string aux;
    aux = getFirstLine();
    size_t start = aux.find_first_of('/');
    size_t end = aux.find_first_of(' ', start);
    if (end - start <= 1) {  // no resource.
        return std::string();  // default string is empty
    }
    return aux.substr(start+1, (end - start)-1);
}

std::string PetitionParser::getBody() {
    petition.clear();
    petition.seekg(0);
    std::string line;
    std::string aux;
    bool bodyReached = false;
    while ( std::getline(petition, line) ) {
        if ( line.empty() ) {
            bodyReached = true;
            continue;
        }
        if ( !bodyReached ) continue;
        aux += line;
        if ( petition.good() ) aux += '\n';
    }
    return aux;
}

