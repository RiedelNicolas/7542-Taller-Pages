//
// Created by riedel on 22/11/20.
//

#include "PetitionProcessor.h"
#include "PetitionGet.h"
#include "PetitionPost.h"
#include "PetitionInvalid.h"

#define GET_ID "GET"
#define POST_ID "POST"

PetitionProcessor::PetitionProcessor(ResourcesRepository &resources,
                                     const std::string &petition)
                                            :resources(resources),
                                            parser(petition) {
    std::string methodId = parser.getMethod();

    if ( methodId == GET_ID ) {
        petitionLogic = new PetitionGet(resources, parser);
    } else if ( methodId == POST_ID ) {
        petitionLogic = new PetitionPost(resources, parser);
    } else {
        petitionLogic = new PetitionInvalid(resources, parser);
    }
}

PetitionProcessor::~PetitionProcessor() {
    delete petitionLogic;
    petitionLogic = nullptr;
}

std::string PetitionProcessor::getAnswer() {
    return petitionLogic->getAnswer();
}

std::string PetitionProcessor::getDisplay() {
    return petitionLogic->getFirstLine();
}

void PetitionProcessor::process() {
    petitionLogic->execute();
}


