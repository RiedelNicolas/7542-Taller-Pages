//
// Created by riedel on 7/11/20.
//

#include "Socket.h"

#define _POSIX_C_SOURCE 201112L  // lo vi en ejemplo de catedra.

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <cstring>

# define INVALID_FD -1
Socket::Socket() {
    this->fd = INVALID_FD;
}

void Socket::connect(std::string host, std::string port) {

}

void Socket::bind(std::string port) {
    struct addrinfo  *result;
    _getaddrinfo(&result, SERVER_MODE, NULL, port);
}

void Socket::listen() {

}

Socket Socket::acceptOne() {
    return Socket();
}

ssize_t Socket::send(const char *buffer, const size_t &len) {
    return 0;
}

ssize_t Socket::receive(const char *buffer, const size_t &len) {
    return 0;
}

Socket::Socket(const int &fd) {
    this->fd = fd;
}






