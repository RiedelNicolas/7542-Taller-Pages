//
// Created by riedel on 2/11/20.
//

#ifndef COMMON_SRC_LOCK_H_
#define COMMON_SRC_LOCK_H_


#include <mutex>

// Clase utilizada para proteger las Race Conditions.
class Lock {
 private:
    std::mutex &mut;
 public:
    // Constructor Protege.
    explicit Lock(std::mutex &mut);
    // El destructor desbloquea el mutex.
    ~Lock();
 private:
    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;
    Lock(Lock&&) = delete;
    Lock& operator=(Lock&&) = delete;
};

#endif  // COMMON_SRC_LOCK_H_
