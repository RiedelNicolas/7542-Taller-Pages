//
// Created by riedel on 9/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CONTROLLER_H
#define INC_7542_TALLER_PAGES_CONTROLLER_H


#include "../common_src/Thread.h"

class Controller: public Thread {
 private:
    bool running;
    const char end;
 public:
    explicit Controller(const char end);
    bool done () override;
    void run() override;
    void stop() override;
};


#endif //INC_7542_TALLER_PAGES_CONTROLLER_H
