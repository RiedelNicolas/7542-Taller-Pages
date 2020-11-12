
#include "Client.h"
#define VALID_ARGS 3
#define POSHOST 1
#define POSPORT 2
int main(int argc, char *argv[]){
    if (argc != VALID_ARGS ) {
        return  0;
    }
    try {
        Client client;
        client.run(argv[POSHOST], argv[POSPORT] );
    } catch (std::exception& e) {
        e.what();
    }
    return 0;
}