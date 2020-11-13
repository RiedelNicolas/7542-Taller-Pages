//
// Created by riedel on 7/11/20.
//

#include "Socket.h"

 //  #define _POSIX_C_SOURCE 201112L  // lo vi en ejemplo de catedra.

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
#define BUFFER_LEN 1024

Socket::Socket() {
    this->fd = INVALID_FD;
}

void Socket::connectTo(std::string host, std::string port) {
    struct addrinfo  *result, *current;
    _getaddrinfo(&result, port.c_str(), host.c_str());
    for (current = result; current !=NULL ; current = current->ai_next) {
        this->fd = socket(current->ai_family,
                          current->ai_socktype, current->ai_protocol);
        if (this->fd == INVALID_FD) continue;
        if(connect(this->fd, current->ai_addr, current->ai_addrlen) != -1) break;
        if(this->fd != INVALID_FD) close(this->fd);
    }
    freeaddrinfo(result);
    if(current == NULL){
        throw SocketException("Unable to connect\n");
    }
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
    Socket peer ( accept( this->fd, NULL, NULL) );
    if( !peer.valido() ){
        throw OSexception(errno);
    }
    return peer;
}

void Socket::send(const char *buffer, const size_t len) {
    ssize_t sent = 0;
    while (sent < (ssize_t) len) {
        ssize_t current = ::send(this->fd, buffer + sent, len-sent, MSG_NOSIGNAL);
        if (current == -1) throw OSexception(errno);
        sent+=current;
    }
}

ssize_t Socket::receive(const char *buffer, const size_t len) {
    ssize_t received = 0;
    while (received < (ssize_t) len) {
        ssize_t current = recv(this->fd, (void *) &buffer[received], len - received, 0);
        if (current == -1) throw OSexception(errno);
        if (current == 0) break;  // se cerro el socket.
        received+=current;
    }
    return received;
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

bool Socket::valido() {
    return (this->fd != INVALID_FD);
}

Socket::~Socket() {
    if( this->valido() ){
        this->shutDown(SHUT_RDWR);
        close(this->fd);
    }
}

void Socket::shutDown(const int mode) {
    shutdown(this->fd, mode);
}

void Socket::endWriting() {
    this->shutDown(SHUT_WR);
}

void Socket::receive(std::string &string) {
    char buffer [BUFFER_LEN];
    ssize_t read;
    do {
        read = this->receive(buffer, BUFFER_LEN);
        string.append(buffer, read);
    } while (read == BUFFER_LEN);
}

void Socket::send(std::string string) {
    this->send(string.c_str(), string.length());
}






