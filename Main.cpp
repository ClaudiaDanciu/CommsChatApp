#include <iostream>
#include "Server.h"
#include "Client.h"

#define SERVER_MODE // Uncomment for server mode, comment for client mode

int main() {
    #ifdef SERVER_MODE
        Server server;
        server.init();
        server.communicate();
    #else
        Client client;
        client.init();
        client.communicate();
    #endif

    return 0;
}

