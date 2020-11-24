//
// Created by riedel on 22/11/20.
//
#include <string>
#include "PetitionGet.h"


void PetitionGet::execute() {
    std::string resource = parser.getResource();
    answer = "HTTP/1.1 200 OK\n";
    if (resource.length() == 0) {
        answer.append("Content-Type: text/html\n\n");
        answer.append(resources.getRoot());
    } else {
        try {
            answer.append("\n");
            answer.append(resources.get(resource));
        } catch (const std::out_of_range& oor) {
            answer = "HTTP/1.1 404 NOT FOUND\n\n";
        }
    }
}



