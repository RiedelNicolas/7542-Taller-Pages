//
// Created by riedel on 22/11/20.
//

#include "PetitionProcessor.h"
#define GET_ID "GET"
#define POST_ID "POST"
PetitionProcessor::PetitionProcessor(ResourcesRepository &resources, const std::string &petition)
                                            :resources(resources),
                                            parser(petition){
    std::string methodId = parser.getMethod();

    if (methodId == GET_ID) {
        petitionLogic = new ;
    }
    else if (methodId == POST_ID ){
        petitionLogic = new;
    }
    else{
        petitionLogic = new;
    }
}

PetitionProcessor::~PetitionProcessor() {
    delete petitionLogic;
}

std::string PetitionProcessor::getAnswer() {
    return petitionLogic->getAnswer();
}

std::string PetitionProcessor::getDisplay() {
    return petitionLogic->getFirstLine();
}


