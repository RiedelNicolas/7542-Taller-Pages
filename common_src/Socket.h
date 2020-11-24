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
    // default constructor.
    Socket();
    // movement constructor.
    Socket(Socket&&) noexcept;
    // Connects to the specified host and port.
    void connectTo(const std::string& host, const std::string& port);
    // Binds to the specified port.
    void bindToPort(const std::string& port);
    // Listen to the previously bound port.
    void listenIncoming();
    // Accepts a peer from the socket. Blocking method.
    Socket acceptOne();
    // sends buffer of the specified len to a previously connect socket.
    // Blocking
    void send(const char* buffer, const size_t& len);
    // sends string to a previously connected socket. Blocking
    void send(const std:: string& string);
    // Loads received message on specified buffer. Blocking
    ssize_t receive(const char* buffer, const size_t& len);
    // loads the received message on a string. Blocking
    void receive(std::string& string);
    // is this a valid socket?
    bool valid() const noexcept;
    //Close socket for writing.
    void endWriting();

    Socket(const Socket&) = delete;
    Socket operator=(const Socket&) = delete;
    Socket& operator=(Socket&&) noexcept;
    ~Socket();
    void close();
};


#endif  // COMMON_SRC_SOCKET_H_
