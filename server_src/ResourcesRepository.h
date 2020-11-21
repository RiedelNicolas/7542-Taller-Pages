//
// Created by riedel on 21/11/20.
//

#ifndef INC_7542_TALLER_PAGES_RESOURCESREPOSITORY_H
#define INC_7542_TALLER_PAGES_RESOURCESREPOSITORY_H


#include <string>
#include <unordered_map>
#include <mutex>

class ResourcesRepository {
 private:
    std::string root;
    std::unordered_map <std::string, std::string> map;
    std::mutex m;
 public:
    ResourcesRepository(const std::string &rootPath);
    const std::string& getRoot();
    const std::string& get(const std::string& key);
    void post(const std::string& key, const std::string resource);
};


#endif //INC_7542_TALLER_PAGES_RESOURCESREPOSITORY_H
