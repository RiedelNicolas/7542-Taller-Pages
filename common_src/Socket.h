//
// Created by riedel on 7/11/20.
//

#ifndef INC_7542_TALLER_PAGES_SOCKET_H
#define INC_7542_TALLER_PAGES_SOCKET_H


#include <string>

class Socket {
private:
    int fd;
    void _getaddrinfo(struct addrinfo  **result, const char* port,
                                        const char* host = NULL );
    void shutDown(const int mode);
 public:

    Socket();
    explicit Socket (const int fd);
    void connectTo(std::string host, std::string port);
    void bindToPort(std::string port);
    void listenIncoming();
    int acceptOne();
    void send (const char* buffer, const size_t len);
    void send(std:: string string);
    ssize_t receive (const char* buffer, const size_t len);
    void receive(std::string& string);
    bool valid();
    void endWriting();
    Socket(const Socket&) = delete;
    Socket operator=(const Socket&) = delete;
    Socket& operator=(Socket&&) noexcept;
    Socket (Socket&&) noexcept;
    ~Socket();
    void close();
};


#endif //INC_7542_TALLER_PAGES_SOCKET_H
