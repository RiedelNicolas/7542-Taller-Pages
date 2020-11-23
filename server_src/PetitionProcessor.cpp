//
// Created by riedel on 22/11/20.
//

#include "PetitionProcessor.h"
#define GET_ID "GET"
#define POST_ID "POST"
PetitionProcessor::PetitionProcessor(ResourcesRepository &resources, const std::string &petition)
                                            :resources(resources){
    std::string methodId = petition.substr
        (0,petition.find_first_of('/') );

    if (methodId == GET_ID) {
        petitionLogic = new;
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


