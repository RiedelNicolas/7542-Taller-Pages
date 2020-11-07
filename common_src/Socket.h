//
// Created by riedel on 7/11/20.
//

#ifndef INC_7542_TALLER_PAGES_SOCKET_H
#define INC_7542_TALLER_PAGES_SOCKET_H


#include <string>

class Socket {
 private:
    int fd;
    explicit Socket(const int& fd);
    void _getaddrinfo(struct addrinfo  **result, const char* port,
                                        const char* host = NULL );

 public:
    Socket();

    void connect(std::string host, std::string port);
    void bindToPort(std::string port);
    void listenIncoming();
    Socket acceptOne();
    ssize_t send (const char* buffer, const size_t& len);
    ssize_t receive (const char* buffer, const size_t& len);
    bool valido();

    ~Socket();
};


#endif //INC_7542_TALLER_PAGES_SOCKET_H
