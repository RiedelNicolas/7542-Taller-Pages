//
// Created by riedel on 2/11/20.
//

#ifndef BLOQUEAR_H_
#define BLOQUEAR_H_


#include <mutex>

// Clase utilizada para proteger las Race Conditions.
class Bloquear {
 private:
    std::mutex &mut;
 public:
    // Constructor Protege.
    explicit Bloquear(std::mutex &mut);
    // El destructor desbloquea el mutex.
    ~Bloquear();
 private:
    Bloquear(const Bloquear&) = delete;
    Bloquear& operator=(const Bloquear&) = delete;
    Bloquear(Bloquear&&) = delete;
    Bloquear& operator=(Bloquear&&) = delete;
};


#endif  // BLOQUEAR_H_