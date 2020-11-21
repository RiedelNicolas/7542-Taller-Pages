//
// Created by riedel on 21/11/20.
//

#include <fstream>
#include <sstream>
#include "ResourcesRepository.h"
#include "../common_src/InvalidFileException.h"

ResourcesRepository::ResourcesRepository(const std::string& rootPath) {
    std::ifstream file(rootPath);
    if( !file.is_open() ){
        throw InvalidFileException("unable to open rootFile");
    }
    std::stringstream sstr;
    while(file >> sstr.rdbuf());
    this->root = sstr.str();
}

const std::string &ResourcesRepository::getRoot() {
    return root;
}

const std::string &ResourcesRepository::get(const std::string &key) {
    this->map[];
}

void ResourcesRepository::post(const std::string& key, const std::string& resource) {
    this->map[key] = resource;
}


