//
// Created by riedel on 22/11/20.
//

#include "PetitionGet.h"

#define


void PetitionGet::execute() {
    std::string resource = parser.getResource();
    answer = "HTTP/1.1 200 OK\n\n";
    if(resource.length() == 0 ){
        answer.append( resources.getRoot() );
    }else{
        try {
            answer.append( resources.get(resource) );
        } catch (const std::out_of_range& oor) {
         answer = "HTTP/1.1 403 FORBIDDEN\n\n";
        }
    }
}



