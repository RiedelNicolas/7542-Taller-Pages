//
// Created by riedel on 2/11/20.
//

#include "Thread.h"
#include <utility>  // Me lo pidio cpplint.

void Thread::start() {
    this->thread = std::thread(&Thread::run, this);
}

void Thread::join() {
    thread.join();
}

Thread::Thread(Thread &&recibido) {
    this->thread = std::move(recibido.thread);
}

Thread &Thread::operator=(Thread &&recibido) {
    this->thread = std::move(recibido.thread);
    return *this;
}
