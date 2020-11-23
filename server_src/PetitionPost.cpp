//
// Created by riedel on 22/11/20.
//

#include "PetitionPost.h"

void PetitionPost::execute() {
    std::string resource = parser.getResource();
    if (resource.size() == 0 ) {
        answer = "HTTP/1.1 403 FORBIDDEN\n\n";
    } else {
        std::string body = parser.getBody();
        resources.post(resource, body);
        answer = "HTTP/1.1 403 FORBIDDEN\n\n";
        answer.append(body);
    }
}
