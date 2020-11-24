//
// Created by riedel on 2/11/20.
//

#include "Lock.h"

Lock::Lock(std::mutex &mut): mut(mut) {
    mut.lock();
}

Lock::~Lock() {
    mut.unlock();
}