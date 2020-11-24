//
// Created by riedel on 21/11/20.
//

#ifndef SERVER_SRC_RESOURCESREPOSITORY_H_
#define SERVER_SRC_RESOURCESREPOSITORY_H_


#include <string>
#include <unordered_map>
#include <mutex>

 // ThreadSafe repository for The HTTP resources.
class ResourcesRepository {
 private:
    std::string root;
    std::unordered_map <std::string, std::string> map;
    std::mutex m;
 public:
    // Constructor receives rootpath.
    explicit ResourcesRepository(const std::string &rootPath);
    const std::string& getRoot() const;
    // gets the resource requested.
    // if the resource is not found "out_of_range" exception is thrown.
    const std::string& get(const std::string& key);
    // stores a new resource into the repository.
    void post(const std::string& key, const std::string& resource);
};


#endif  // SERVER_SRC_RESOURCESREPOSITORY_H_
