//
// Created by riedel on 13/11/20.
//

#ifndef SERVER_SRC_PETITIONPARSER_H_
#define SERVER_SRC_PETITIONPARSER_H_

#include <string>
#include <sstream>
  // Able to parse an htpp petition.
class PetitionParser {
 private:
    std::istringstream petition;
 public:
    explicit PetitionParser(const std::string& in);
    std::string getMethod();
    std::string getFirstLine();
    // Returns the resource name.
    std::string getResource();
    // Returns the body of the petition.
    std::string getBody();
};

#endif  // SERVER_SRC_PETITIONPARSER_H_
