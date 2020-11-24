//
// Created by riedel on 22/11/20.
//

#include "PetitionLogic.h"

std::string PetitionLogic::getFirstLine() {
    return parser.getFirstLine();
}

std::string PetitionLogic::getAnswer() {
    return this->answer;
}

PetitionLogic::PetitionLogic(ResourcesRepository &resources,
                             PetitionParser &parser):
                             resources(resources),
                             parser(parser){
}


