
#include <iostream>
#include "Server.h"
#define VALID_ARGS 3
#define POSPATH 2
#define POSPORT 1

int main(int argc, char *argv[]) {
    if ( argc != VALID_ARGS ) {
        return  -1;
    }
    try {
        Server server(argv[POSPORT], argv[POSPATH]);
        server();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Unknown error"<< std::endl;
    }
    return 0;
}
