#ifndef CLIENT_H
#define CLIENT_H

#include "Comms.h"

class Client : public Comms {
public:
    void init() override {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("Client socket creation failed");
            exit(EXIT_FAILURE);
        }

        address.sin_family = AF_INET;
        address.sin_port = htons(PORT);

        if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
            perror("Invalid address or address not supported");
            exit(EXIT_FAILURE);
        }

        if (connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("Connection failed");
            exit(EXIT_FAILURE);
        }

        std::cout << "Connected to the server!" << std::endl;
    }

    void communicate() override {
        while (true) {
            std::cout << "Client: ";
            std::string message;
            std::getline(std::cin, message);
            send(sockfd, message.c_str(), message.length(), 0);

            if (message == "QUIT") {
                std::cout << "Client exiting..." << std::endl;
                break;
            }

            memset(buffer, 0, BUFFER_SIZE);
            int bytesRead = read(sockfd, buffer, BUFFER_SIZE);
            if (bytesRead == -1) {
                perror("Read error");
                break;
            }

            std::cout << "Server: " << buffer << std::endl;
        }
    }
};

#endif // CLIENT_H

