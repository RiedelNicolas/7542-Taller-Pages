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

#include "SocketException.h"
#include "OSexception.h"

#define INVALID_FD -1
#define MAX_LISTEN 30

Socket::Socket() {
    this->fd = INVALID_FD;
}

void Socket::connect(std::string host, std::string port) {

}

void Socket::bindToPort(std::string port) {
    struct addrinfo  *result, *current;
    _getaddrinfo(&result, port.c_str());
    for (current = result; current != NULL; current=current->ai_next) {
        this->fd = socket(current->ai_family,
                          current->ai_socktype, current->ai_protocol);
        if (this->fd == INVALID_FD) continue;
        int val = 1;
        setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (bind(this->fd, current->ai_addr, current->ai_addrlen) == 0 ) break;
        close(this->fd);
    }
    freeaddrinfo(result);
    if(current == NULL){
        throw SocketException("couldnt bind \n");
    }
}

void Socket::listenIncoming() {
    if (listen(this->fd, MAX_LISTEN) != 0) {
        throw OSexception(errno);
    }
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

Socket::Socket(const int &fd) : fd(fd) {
}

//wrapper
void Socket::_getaddrinfo(struct addrinfo **result, const char* port, const char* host) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int error = getaddrinfo(host, port, &hints, result);
    if(error != 0) throw SocketException(  gai_strerror(error) );
}






