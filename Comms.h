#ifndef COMMS_H
#define COMMS_H

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class Comms {
protected:
    int sockfd;                      // Socket descriptor
    struct sockaddr_in address;      // Socket address structure
    char buffer[BUFFER_SIZE];        // Buffer for sending/receiving messages

public:
    virtual void init() = 0;         // Pure virtual function for initialization
    virtual void communicate() = 0;  // Pure virtual function for communication

    virtual ~Comms() { close(sockfd); }  // Destructor to close socket
};

#endif // COMMS_H

