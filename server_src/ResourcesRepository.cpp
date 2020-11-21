//
// Created by riedel on 21/11/20.
//

#include "ResourcesRepository.h"

ResourcesRepository::ResourcesRepository(const std::string &root) : root(root) {}

const std::string &ResourcesRepository::getRoot() {
    return root;
}

const std::string &ResourcesRepository::get(const std::string &key) {
    this->map
}


