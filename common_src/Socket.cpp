//
// Created by riedel on 7/11/20.
//

#include "Socket.h"

#include <unistd.h>
#include <sys/socket.h>
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

Socket::Socket(int fd) : fd(fd) {
}

void Socket::connectTo(const std::string& host, const std::string& port) {
    struct addrinfo  *result, *current;
    _getaddrinfo(&result, port.c_str(), host.c_str());
    for (current = result; current !=NULL ; current = current->ai_next) {
        this->fd = socket(current->ai_family,
                          current->ai_socktype, current->ai_protocol);
        if (this->fd == INVALID_FD) continue;
        if (connect(this->fd, current->ai_addr, current->ai_addrlen) != -1)
            break;
        if (this->fd != INVALID_FD) ::close(this->fd);
    }
    freeaddrinfo(result);
    if (current == NULL) {
        throw SocketException("Unable to connect\n");
    }
}

void Socket::bindToPort(const std::string& port) {
    struct addrinfo  *result, *current;
    _getaddrinfo(&result, port.c_str());
    for (current = result; current != NULL; current=current->ai_next) {
        this->fd = socket(current->ai_family,
                          current->ai_socktype, current->ai_protocol);
        if (this->fd == INVALID_FD) continue;
        int val = 1;
        setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (bind(this->fd, current->ai_addr, current->ai_addrlen) == 0 ) break;
        ::close(this->fd);
    }
    freeaddrinfo(result);
    if (current == NULL) {
        throw SocketException("couldnt bind \n");
    }
}

void Socket::listenIncoming() {
    if (listen(this->fd, MAX_LISTEN) != 0) {
        throw OSexception(errno);
    }
}

Socket Socket::acceptOne() {
    int peer =  accept(this->fd, NULL, NULL);
    return Socket(peer);  // RVO
}

void Socket::send(const char *buffer, const size_t& len) {
    ssize_t sent = 0;
    while (sent < (ssize_t) len) {
        ssize_t current = ::send(this->fd, buffer + sent,
                                 len-sent, MSG_NOSIGNAL);
        if (current == -1) throw OSexception(errno);
        sent+=current;
    }
}

ssize_t Socket::receive(const char *buffer, const size_t& len) {
    ssize_t received = 0;
    while (received < (ssize_t) len) {
        ssize_t current = recv(this->fd, (void *) &buffer[received],
                               len - received, 0);
        if (current == -1) throw OSexception(errno);
        if (current == 0) break;  // se cerro el socket.
        received+=current;
    }
    return received;
}

  // wrapper
void Socket::_getaddrinfo(struct addrinfo **result, const char* port,
                                                    const char* host) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int error = getaddrinfo(host, port, &hints, result);
    if (error != 0) throw SocketException(  gai_strerror(error) );
}

bool Socket::valid() const noexcept {
    return (this->fd != INVALID_FD);
}


void Socket::shutDown(const int mode) {
    shutdown(this->fd, mode);
}

void Socket::endWriting() {
    this->shutDown(SHUT_WR);
}

void Socket::receive(std::string &string) {
    char buffer[BUFFER_LEN];
    ssize_t read;
    do {
        read = this->receive(buffer, BUFFER_LEN);
        string.append(buffer, read);
    } while (read == BUFFER_LEN);
}

void Socket::send(const std::string& string) {
    this->send(string.c_str(), string.length());
}

Socket::Socket(Socket&& in) noexcept {
    this->fd = in.fd;
    in.fd = INVALID_FD;
}

Socket &Socket::operator=(Socket&& in) noexcept {
    if ( this == &in ) {
        return *this;
    }
    this->fd = in.fd;
    in.fd = INVALID_FD;
    return *this;
}

void Socket::close() {
    if ( this->valid() ) {
        this->shutDown(SHUT_RDWR);
        ::close(this->fd);
        this->fd = INVALID_FD;
    }
}

Socket::~Socket() {
    this->close();
}






