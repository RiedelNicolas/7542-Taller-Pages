//
// Created by riedel on 2/11/20.
//

#ifndef COMMON_SRC_THREAD_H_
#define COMMON_SRC_THREAD_H_


#include <thread>
// Clase abstracta Thread.
// Fuertemente basada en la brindada por la catedra.
class Thread {
 private:
    std::thread thread;
 public:
    Thread() = default;
    void start();
    void join();
    virtual void run() = 0;  // abstract.
    virtual void stop() = 0;
    virtual bool done() = 0;
    virtual ~Thread() = default;
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
};

#endif  // COMMON_SRC_THREAD_H_
