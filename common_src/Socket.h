//
// Created by riedel on 7/11/20.
//

#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_


#include <string>

class Socket {
 private:
    int fd;
    void _getaddrinfo(struct addrinfo  **result, const char* port,
                                        const char* host = NULL);
    void shutDown(const int mode);
    explicit Socket(const int fd);

 public:
    Socket();
    Socket(Socket&&) noexcept;
    void connectTo(std::string host, std::string port);
    void bindToPort(std::string port);
    void listenIncoming();
    Socket acceptOne();
    void send(const char* buffer, const size_t len);
    void send(std:: string string);
    ssize_t receive(const char* buffer, const size_t len);
    void receive(std::string& string);
    bool valid();
    void endWriting();
    Socket(const Socket&) = delete;
    Socket operator=(const Socket&) = delete;
    Socket& operator=(Socket&&) noexcept;
    ~Socket();
    void close();
};


#endif  // COMMON_SRC_SOCKET_H_
