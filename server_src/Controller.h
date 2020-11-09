//
// Created by riedel on 9/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CONTROLLER_H
#define INC_7542_TALLER_PAGES_CONTROLLER_H


#include "../common_src/Thread.h"

class Controller: Thread {
 private:
    bool finalizo;
    const char end;
 public:
    Controller(const char end);
    bool done();
    void run() override;
};


#endif //INC_7542_TALLER_PAGES_CONTROLLER_H
