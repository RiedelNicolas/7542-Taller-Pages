//
// Created by riedel on 13/11/20.
//

#ifndef INC_7542_TALLER_PAGES_PRINTMONITOR_H
#define INC_7542_TALLER_PAGES_PRINTMONITOR_H

#include <string>
#include <mutex>

class PrintMonitor {
 private:
    std::mutex m;
 public:
    void print(const std::string& in);
};


#endif //INC_7542_TALLER_PAGES_PRINTMONITOR_H
