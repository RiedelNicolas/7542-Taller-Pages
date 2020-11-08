//
// Created by riedel on 2/11/20.
//

#include "Bloquear.h"

Bloquear::Bloquear(std::mutex &mut): mut(mut) {
    mut.lock();
}

Bloquear::~Bloquear() {
    mut.unlock();
}