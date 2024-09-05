#ifndef SERVER_H
#define SERVER_H

#include "Comms.h"

class Server : public Comms {
public:
    void init() override {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("Server socket creation failed");
            exit(EXIT_FAILURE);
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("Binding failed");
            exit(EXIT_FAILURE);
        }

        if (listen(sockfd, 3) < 0) {
            perror("Listening failed");
            exit(EXIT_FAILURE);
        }

        std::cout << "Server initialized and waiting for connections..." << std::endl;
    }

    void communicate() override {
        int addrlen = sizeof(address);
        int new_socket = accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        std::cout << "Client connected!" << std::endl;

        while (true) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytesRead = read(new_socket, buffer, BUFFER_SIZE);
            if (bytesRead == -1) {
                perror("Read error");
                break;
            }

            std::cout << "Client: " << buffer << std::endl;

            if (strncmp(buffer, "QUIT", 4) == 0) {
                std::cout << "Client disconnected." << std::endl;
                break;
            }

            std::cout << "Server: ";
            std::string message;
            std::getline(std::cin, message);
            send(new_socket, message.c_str(), message.length(), 0);
        }

        close(new_socket);
    }
};

#endif // SERVER_H

