//
// Created by riedel on 9/11/20.
//

#ifndef INC_7542_TALLER_PAGES_CONTROLADOR_H
#define INC_7542_TALLER_PAGES_CONTROLADOR_H


#include "../common_src/Thread.h"

class Controlador: Thread {
    bool finalizo;
    const char end;
};


#endif //INC_7542_TALLER_PAGES_CONTROLADOR_H
