//
// Created by riedel on 22/11/20.
//

#include "PetitionLogic.h"

PetitionLogic::PetitionLogic(const std::string &petition, ResourcesRepository& resources
                                                ):parser(petition),resources(resources)
                                                        {
}

std::string PetitionLogic::getFirstLine() {
    return parser.getFirstLine();
}
