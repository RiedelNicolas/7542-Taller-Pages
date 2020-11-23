//
// Created by riedel on 22/11/20.
//

#include "PetitionInvalid.h"

void PetitionInvalid::execute() {
  answer = "HTTP/1.1 403 FORBIDDEN\n\n";
}
