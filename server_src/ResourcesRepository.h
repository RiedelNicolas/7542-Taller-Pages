//
// Created by riedel on 21/11/20.
//

#ifndef SERVER_SRC_RESOURCESREPOSITORY_H_
#define SERVER_SRC_RESOURCESREPOSITORY_H_


#include <string>
#include <unordered_map>
#include <mutex>

class ResourcesRepository {
 private:
    std::string root;
    std::unordered_map <std::string, std::string> map;
    std::mutex m;
 public:
    explicit ResourcesRepository(const std::string &rootPath);
    const std::string& getRoot();
    const std::string& get(const std::string& key);
    void post(const std::string& key, const std::string& resource);
};


#endif  // SERVER_SRC_RESOURCESREPOSITORY_H_
